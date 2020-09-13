#ifndef INTERFACE_CLASS
#define INTERFACE_CLASS

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "user.hpp"
#include "group.hpp"
#include "badexception.hpp"
#include "directory.hpp"

enum CopyTypeEnum
{
	copied,
	moved,
	none
};

class Interface
{
public:
	Interface(std::string _source_address);
	void initial_files();
	void process(std::string line);
	void add_user(std::string username, std::string password);
	void login(std::string username, std::string password);
	void add_group(std::string group_name);
	void add_to_group(std::string group_name, std::string username);
	void make_directory(std::string directory_name, std::string owner);
	void copy(std::string source_path, std::string destination_path);
	void move(std::string source_path, std::string destination_path);
	void remove(std::string path);
	void print_directory();
	void upload(std::string real_file_name, std::string path);
	void download(std::string path, std::string real_file_name);
	void change_directory(std::string path);
	void elem_info(std::string path);
	void change_mode(std::vector<std::string> splitted_line);
	void change_owner(std::string username, std::string path);
	void change_group(std::string groupname, std::string path);
	bool go_back();
	void userlist();
	void show_storage();
	void demote(std::string username);
	void promote(std::string username);
	std::vector<std::string> get_usernames();
	std::vector<std::string> get_files();
	std::vector<std::string> get_directories();
	void make_copy_directory(std::string _copied_directory);
	void make_copy_file(std::string _copied_file);
	void make_move_directory(std::string _moved_directory);
	void make_move_file(std::string _moved_file);
	bool remove_file_by_name(std::string file_name);
	bool remove_directory_by_name(std::string directory_name);
	bool usual_user_can_go_back(std::string username);
	std::string get_file_details_by_name(std::string file_name);
	std::string get_directory_details_by_name(std::string directory_name);
	void add_copied_element();

	void set_session_id(std::string username, int random_number){session_ids[username] = random_number;}
	bool check_session_id(int _session_id);
	std::string get_online_username(int _session_id);
	User* find_online_user(int _session_id);
	void logout(int _session_id);
	std::string get_current_directory_name(){return path[path.size() - 1];}
	void change_current_directory_name(std::string new_name){path.push_back(new_name);}
private:
	std::vector<std::string> split_line(std::string command);
	std::vector<std::string> split_address(std::string command);
	int find_index_of_user(std::string username);
	int find_index_of_group(std::string group_name);
	void change_role(std::string username, UserTypeEnum role);
	Directory* find_last_directory(std::string path);
	Directory* find_directory(std::string path);
	File* find_file(std::string path);
	void find_size_of_file(std::string path);
	Directory* find_directory_by_name(std::string directory_name);
	File* find_file_by_name(std::string file_name);
	void remove_from_source_directory_by_name(std::string _moved_directory);
	void remove_from_source_file_by_name(std::string _moved_file);

	std::vector<User*> users;
	std::vector<Group*> groups;
	int index_of_current_user;
	std::string current_location;
	std::map<std::string, UserTypeEnum> roles;	
	std::vector<Directory*> directories;
	std::vector<File*> files;
	Directory* current_directory;
	std::string source_address;
	std::map<std::string,int> session_ids;

	Directory* copied_directory = NULL;
	File* copied_file= NULL;
	CopyTypeEnum copied_or_moved = none;
	std::vector<std::string> path = {""}; 
};

#endif
