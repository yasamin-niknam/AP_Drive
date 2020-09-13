#include "directory.hpp"

using namespace std;

Directory::Directory(string _name, string _path, string _owner_username) 
		: Element(_name, _path, _owner_username) {}

Directory* Directory::add_directory(string directory_name, string path, string username)
{	
	for (int i = 0; i < directories.size(); i++)
	{
		if(directories[i]->is_same_element(directory_name))
			throw BadException();
	}
	Directory* new_directory = new Directory(directory_name, path, username);
	directories.push_back(new_directory);
	return new_directory;
}

Directory* Directory::find_directory(string directory_name)
{
	for (int i = 0; i < directories.size(); i++)
	{
		if(directories[i]->is_same_element(directory_name))
			return directories[i];
	}
	return NULL;
}

File* Directory::find_file(string file_name)
{
	for (int i = 0; i < files.size(); i++)
	{
		if(files[i]->is_same_element(file_name))
			return files[i];
	}
	return NULL;
}

void Directory::insert_file(File* new_file)
{
	File* added_file;
	added_file = new_file;
	files.push_back(added_file);
}

void Directory::remove_file(File* file)
{
	for (int i = 0; i < files.size(); ++i)
	{
		if(files[i] == file)
		{
			delete files[i];
			files.erase(files.begin() + i);
			break;
		}
	}
}

void Directory::move_file(File* file)
{
	for (int i = 0; i < files.size(); ++i)
	{
		if(files[i] == file)
		{
			files.erase(files.begin() + i);
			break;
		}
	}
}

void Directory::remove_directory(Directory* directory)
{
	for (int i = 0; i < directories.size(); ++i)
	{
		if(directories[i] == directory)
		{
			directories[i]->clean();
			directories.erase(directories.begin() + i);
			break;
		}

	}
}

void Directory::clean()
{
	while(files.size() != 0)
	{
		delete files[0];
		files.erase(files.begin());
	}
	for (int i = 0; i < directories.size(); ++i)
		directories[i]->clean();
	while(directories.size() != 0)
	{
		delete directories[0];
		directories.erase(directories.begin());
	}
}

int Directory::calc_storage()
{
	int storage = 0;

	for (int i = 0; i < files.size(); ++i)
	{
		storage += files[i]->size();
	}
	for (int i = 0; i < directories.size(); ++i)
	{
		storage += directories[i]->calc_storage();
	}
	return storage;
}

void Directory::copy_directory(Directory* destination)
{
	destination->add_directory(name, path, owner_username);
}