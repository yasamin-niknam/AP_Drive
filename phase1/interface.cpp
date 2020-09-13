#include "interface.hpp"

#define ALPHABETIC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@._-0123456789,;/+"
#define ALPHABETIC_ADDRESS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@._-0123456789,;+"
#define NOT_FOUND -1

using namespace std;


Interface::Interface(string _source_address)
{
	add_user("root", "root");
	change_role("root", superuser);
	index_of_current_user = NOT_FOUND;
	current_location = "";
	source_address = _source_address;
}

int Interface::find_index_of_user(string username)
{
	for (int i = 0; i < users.size(); i++)
	{
		if(users[i]->is_same_username(username))
			return i;
	}
	return NOT_FOUND;
}

int Interface::find_index_of_group(string group_name)
{
	for (int i = 0; i < groups.size(); i++)
	{
		if(groups[i]->is_same_group(group_name))
			return i;
	}
	return NOT_FOUND;
}

void Interface::change_role(string username, UserTypeEnum role)
{
	int index_of_founded_user = find_index_of_user(username);
	users[index_of_founded_user]->change_role(role);
}

vector<string> Interface::split_address(string command)
{
	vector<string> splitted_command;
	string word;
	while(true){
		int ptr_to_first_of_word = command.find_first_of(ALPHABETIC_ADDRESS);
		if(ptr_to_first_of_word == NOT_FOUND)
			break;
		int ptr_to_end_of_word =command.find_first_not_of(ALPHABETIC_ADDRESS, ptr_to_first_of_word);
		if(ptr_to_end_of_word == NOT_FOUND)
		{
			word = command.substr(ptr_to_first_of_word);
			splitted_command.push_back(word);
			break;
		}
		word = command.substr(ptr_to_first_of_word, (ptr_to_end_of_word - ptr_to_first_of_word));
		splitted_command.push_back(word);
		command = command.substr(ptr_to_end_of_word);
	}
	return splitted_command;
}

vector<string> Interface::split_line(string command)
{
	vector<string> splitted_command;
	string word;
	while(true){
		int ptr_to_first_of_word = command.find_first_of(ALPHABETIC);
		if(ptr_to_first_of_word == NOT_FOUND)
			break;
		int ptr_to_end_of_word =command.find_first_not_of(ALPHABETIC, ptr_to_first_of_word);
		if(ptr_to_end_of_word == NOT_FOUND)
		{
			word = command.substr(ptr_to_first_of_word);
			splitted_command.push_back(word);
			break;
		}
		word = command.substr(ptr_to_first_of_word, (ptr_to_end_of_word - ptr_to_first_of_word));
		splitted_command.push_back(word);
		command = command.substr(ptr_to_end_of_word);
	}
	return splitted_command;
}

void Interface::add_user(string username, string password)
{
	if(username == "root" && password == "root")
	{
		User* new_user = new User(username, password);
		users.push_back(new_user);
	}
	else
	{
		if(index_of_current_user == NOT_FOUND)
			throw BadException("No one is logged in");
		bool is_valid_user = (users[index_of_current_user]->get_role() == superuser) || 
							(users[index_of_current_user]->get_role() == admin);
		if(!is_valid_user)
			throw BadException("Regular users can not add anyone");
		int index_of_founded_user = find_index_of_user(username);
		if(index_of_founded_user != NOT_FOUND)
			throw BadException("This user Already exists");
		User* new_user = new User(username, password);
		users.push_back(new_user);
	}	
	if(index_of_current_user == NOT_FOUND)
		index_of_current_user = find_index_of_user(username);
	Directory* new_directory = new Directory(username, source_address, username);
	directories.push_back(new_directory);
}

void Interface::login(string username, string password)
{
	int index_of_user = find_index_of_user(username);
	if(index_of_user == NOT_FOUND)
		throw BadException("This user does not exist");
	if(users[index_of_user]->check_password(password))
		index_of_current_user = index_of_user;
	else
		throw BadException("Password is wrong");
	for (int i = 0; i < directories.size(); ++i)
	{
		if(directories[i]->is_same_element(username))
		{
			current_directory = directories[i];
			current_location = "/" + username;
		}	
	}
}

void Interface::add_group(string group_name)
{
	if(index_of_current_user == NOT_FOUND)
		throw BadException("No one has logged in");
	if(find_index_of_group(group_name) != NOT_FOUND)
		throw BadException("This group already exists");
	Group* new_group = new Group(users[index_of_current_user]->get_username(), group_name);
	groups.push_back(new_group);
}

void Interface::add_to_group(std::string group_name, std::string username)
{
	int index_of_group = find_index_of_group(group_name);
	int index_of_user = find_index_of_user(username);
	if(index_of_group == NOT_FOUND)
		throw BadException("This group does not exists");
	if(index_of_user == NOT_FOUND)
		throw BadException("No one has logged in");
	if(groups[index_of_group]->is_in_group(users[index_of_current_user]->get_username()))
		groups[index_of_group]->add_user(username);
	else
		throw BadException("This user is not in this group");
}

void Interface::make_directory(string directory_name, string owner)
{
	current_directory->add_directory(directory_name, current_location, owner);
}

File* Interface::find_file(string path)
{
	Directory* founded_directory = NULL;
	vector<string> splitted_path = split_address(path);
	if(path[0] != '/')
	{
		vector<string> splitted_current_location = split_address(current_location);
		for (int i = (splitted_current_location.size() - 1); i >= 0 ; i--)
		{
			splitted_path.insert(splitted_path.begin(), splitted_current_location[i]);
		}
	}
	for (int i = 0; i < directories.size(); ++i)
	{
		if(directories[i]->is_same_element(splitted_path[0]))
		{
			founded_directory = directories[i];
			break;
		}
	}
	if(splitted_path.size() > 2)
	{	
		for (int i = 1; i < (splitted_path.size() - 1); ++i)
		{
			if(founded_directory == NULL)
				break;
			founded_directory = founded_directory->find_directory(splitted_path[i]);
		}
	}
	return founded_directory->find_file(splitted_path[splitted_path.size() - 1]);
}

Directory* Interface::find_last_directory(string path)
{
	Directory* founded_directory = NULL;
	vector<string> splitted_path = split_address(path);
	if(path[0] != '/')
	{
		vector<string> splitted_current_location = split_address(current_location);
		for (int i = (splitted_current_location.size() - 1); i >= 0 ; i--)
		{
			splitted_path.insert(splitted_path.begin(), splitted_current_location[i]);
		}
	}
	for (int i = 0; i < directories.size(); ++i)
	{
		if(directories[i]->is_same_element(splitted_path[0]))
		{
			founded_directory = directories[i];
			break;
		}
	}
	for (int i = 1; i < splitted_path.size(); ++i)
	{
		if(founded_directory == NULL)
			break;
		founded_directory = founded_directory->find_directory(splitted_path[i]);
	}
	return founded_directory;
}

Directory* Interface::find_directory(string path)
{
	Directory* founded_directory = NULL;
	vector<string> splitted_path = split_address(path);
	if(path[0] != '/')
	{
		vector<string> splitted_current_location = split_address(current_location);
		for (int i = (splitted_current_location.size() - 1); i >= 0 ; i--)
		{
			splitted_path.insert(splitted_path.begin(), splitted_current_location[i]);
		}
	}
	for (int i = 0; i < directories.size(); ++i)
	{
		if(directories[i]->is_same_element(splitted_path[0]))
		{
			founded_directory = directories[i];
			break;
		}
	}
	for (int i = 1; i < (splitted_path.size() - 1); ++i)
	{
		if(founded_directory == NULL)
			break;
		founded_directory = founded_directory->find_directory(splitted_path[i]);
	}
	return founded_directory;
}

void Interface::copy(string source_path, string destination_path)
{
	File* source_file;
	File* destination_file;
	Directory* source_directory;
	Directory* destination_directory;
	source_file = find_file(source_path);
	destination_file = find_file(destination_path);
	source_directory = find_last_directory(source_path);
	destination_directory = find_last_directory(destination_path);
	if((source_file != NULL) && (destination_file != NULL))
	{
		source_file->copy_file(destination_file);
	}
	else if((source_directory != NULL) && (destination_directory != NULL))
	{
		source_directory->copy_directory(destination_directory);
	}
	else if((destination_directory != NULL) && (source_file != NULL))
	{
		destination_directory->insert_file(source_file);
	}
}

void Interface::move(string source_path, string destination_path)
{
	File* source;
	Directory* source_directory;
	Directory* destination_directory;
	source = find_file(source_path);
	source_directory = find_directory(source_path);
	destination_directory = find_directory(destination_path);
	bool invalid_address = (source == NULL) || (source_directory == NULL) || (destination_directory == NULL);
	if(invalid_address)
		throw BadException("Adress is invalid");
	source->move(destination_directory);
	source_directory->move_file(source);
}

void Interface::remove(std::string path)
{
	Directory* directory = find_directory(path);
	File* founded_file = find_file(path);
	Directory* founded_directory = find_last_directory(path);
	if(directory == NULL)
		throw BadException("This path does not exist");
	if(founded_file != NULL)
		directory->remove_file(founded_file);
	if(founded_directory != NULL)
		directory->remove_directory(founded_directory);
}

void Interface::print_directory()
{
	cout << current_location << endl;
}

void Interface::upload(string real_file_name, string path)
{
	File* destination_file = find_file(path);
	Directory* destination_directory = NULL;
	if(destination_file == NULL)
	{
		destination_directory = find_last_directory(path);
	}
	if((destination_file == NULL) && (destination_directory == NULL))
		throw BadException("Path is wrong");
	ifstream inputfile(source_address + "/" + real_file_name, ifstream::binary);
	if(inputfile) 
	{
	    inputfile.seekg (0, inputfile.end);
	    int length = inputfile.tellg();
	    inputfile.seekg (0, inputfile.beg);
	    vector<char> buffer(length);
	    inputfile.read (buffer.data(), length);
	    inputfile.close();
	    if(destination_file != NULL)
	    {
			destination_file->change_info(buffer);
	    }
		else
		{
			if(path[0] != '/')
				path = current_location + "/" + path;
			destination_file = new File(real_file_name, path, users[index_of_current_user]->get_username());
			destination_file->change_info(buffer);
			destination_directory->insert_file(destination_file);
		}
	}
}

void Interface::download(string path, string real_file_name)
{
	File* source = find_file(path);
	if(source == NULL)
	{
		throw BadException("Path does not exist");
	}
	vector<char> buffer = source->get_info();
	ofstream outfile(source_address + "/" + real_file_name, ofstream::binary);
	outfile.write(buffer.data(),buffer.size());
  	outfile.close();
}

void Interface::change_directory(string path)
{
	Directory* new_location = find_last_directory(path);
	if(new_location == NULL)
		throw BadException("Path does not exist");
	else
	{
		current_directory = new_location;
		if(path[0] == '/')
			current_location = path;
		else
			current_location = current_location + path; 
	}
}

void Interface::elem_info(string path)
{	
	Directory* founded_directory = find_last_directory(path);
	File* founded_file = find_file(path);
	if((founded_directory == NULL) && (founded_file == NULL))
		throw BadException("Path does not exist");
	else if(founded_file != NULL)
	{
		founded_file->elem_info("file");
	}
	else if(founded_directory != NULL)
	{
		founded_directory->elem_info("dir");
	}
}

void Interface::find_size_of_file(string path)
{
	File* founded_file;
	founded_file = find_file(path);
	founded_file->show_size();
}

void Interface::change_mode(vector<string> splitted_line)
{
	Directory* founded_directory = find_directory(splitted_line[4]);
	File* founded_file = find_file(splitted_line[4]);
	if((founded_directory == NULL) && (founded_file == NULL))
		throw BadException("Path does not exist");
	else if(founded_file != NULL)
	{
		if(founded_file->is_owner(users[index_of_current_user]->get_username()))
			founded_file->change_mode(splitted_line[1], splitted_line[2], splitted_line[3]);
		else 
			throw BadException("Only owner can change mode");	
	}
	else if(founded_directory != NULL)
	{
		if(founded_directory->is_owner(users[index_of_current_user]->get_username()))
			founded_directory->change_mode(splitted_line[1], splitted_line[2], splitted_line[3]);	
		else 
			throw BadException("Only owner can change mode");	
	}
}

void Interface::change_group(string groupname, string path)
{
	Directory* founded_directory = find_directory(path);
	File* founded_file = find_file(path);
	if((founded_directory == NULL) && (founded_file == NULL))
		throw BadException("Path does not exist");
	else if(founded_file != NULL)
	{
		if(founded_file->is_owner(users[index_of_current_user]->get_username()))
			founded_file->change_group(groupname);
	}
	else if(founded_directory != NULL)
	{
		if(founded_directory->is_owner(users[index_of_current_user]->get_username()))
			founded_directory->change_group(groupname);
	}	
}

void Interface::change_owner(string username, string path)
{
	Directory* founded_directory = find_directory(path);
	File* founded_file = find_file(path);
	if((founded_directory == NULL) && (founded_file == NULL))
		throw BadException("Path does not exist");
	else if(founded_file != NULL)
	{
		if(founded_file->is_owner(users[index_of_current_user]->get_username()))
			founded_file->change_owner(username);
	}
	else if(founded_directory != NULL)
	{
		if(founded_directory->is_owner(users[index_of_current_user]->get_username()))
			founded_directory->change_owner(username);
	}
}

void Interface::promote(string username,string new_role)
{
	if(users[index_of_current_user]->get_role() == superuser)
	{
		int index_of_user = find_index_of_user(username);
		if(index_of_user == NOT_FOUND)
			throw BadException("User does not exist");
		users[index_of_user]->promote(new_role);
	}
}

void Interface::demote(string username,string new_role)
{
	if(users[index_of_current_user]->get_role() == superuser)
	{
		int index_of_user = find_index_of_user(username);
		if(index_of_user == NOT_FOUND)
			throw BadException("User does not exist");
		users[index_of_user]->demote(new_role);
	}	
}

void Interface::userlist()
{
	bool is_valid_user = (users[index_of_current_user]->get_role() == superuser) || 
						(users[index_of_current_user]->get_role() == admin);
	if(is_valid_user)
	{
		for (int i = 0; i < users.size(); ++i)
		{
			cout << users[i]->get_username() << endl;
		}
	}
	else 
		throw BadException("Ususal users can not see userlist");
}

void Interface::show_storage()
{
	int storage = 0;
	for (int i = 0; i < directories.size(); ++i)
	{
		storage += directories[i]->calc_storage();
	}
	cout << storage << " Kb" << endl;
}

void Interface::process(std::string line)
{
	try
	{
		vector<string> splitted_line = split_line(line);
		if(index_of_current_user == NOT_FOUND)
		{
			if(splitted_line[0] != "login") 
				throw BadException("No one is logged in");
		}
		if(splitted_line[0] == "add_user")
		{
			add_user(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "login")
		{
			login(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "add_group")
		{
			add_group(splitted_line[1]);
		}
		else if(splitted_line[0] == "add_to_group")
		{
			add_to_group(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "upload")
		{
			upload(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "download")
		{
			download(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "make_directory")
		{
			make_directory(splitted_line[1], users[index_of_current_user]->get_username());
		}
		else if(splitted_line[0] == "copy")
		{
			copy(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "move")
		{
			move(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "remove")
		{
			remove(splitted_line[1]);
		}
		else if(splitted_line[0] == "print_directory")
		{
			print_directory();
		}
		else if(splitted_line[0] == "change_directory")
		{
			change_directory(splitted_line[1]);
		}
		else if(splitted_line[0] == "elem_info")
		{
			elem_info(splitted_line[1]);
		}
		else if (splitted_line[0] == "file_size")
		{
			find_size_of_file(splitted_line[1]);
		}
		else if(splitted_line[0] == "change_mode")
		{
			change_mode(splitted_line);
		}
		else if(splitted_line[0] == "change_owner")
		{
			change_owner(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "change_group")
		{
			change_group(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "promote")
		{
			promote(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "demote")
		{
			demote(splitted_line[1], splitted_line[2]);
		}
		else if(splitted_line[0] == "userlist")
		{
			userlist();
		}
		else if(splitted_line[0] == "storage")
		{
			show_storage();
		}
	}
	catch(BadException ex)
	{
		ex.print();
	}	
}
