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

class Interface
{
public:
	Interface(std::string _source_address);
	void process(std::string line);
private:
	std::vector<std::string> split_line(std::string command);
	std::vector<std::string> split_address(std::string command);
	void add_user(std::string username, std::string password);
	int find_index_of_user(std::string username);
	int find_index_of_group(std::string group_name);
	void login(std::string username, std::string password);
	void add_group(std::string group_name);
	void add_to_group(std::string group_name, std::string username);
	void change_role(std::string username, UserTypeEnum role);
	void make_directory(std::string directory_name, std::string owner);
	Directory* find_last_directory(std::string path);
	Directory* find_directory(std::string path);
	File* find_file(std::string path);
	void copy(std::string source_path, std::string destination_path);
	void move(std::string source_path, std::string destination_path);
	void remove(std::string path);
	void print_directory();
	void upload(std::string real_file_name, std::string path);
	void download(std::string path, std::string real_file_name);
	void change_directory(std::string path);
	void elem_info(std::string path);
	void change_mode(std::vector<std::string> splitted_line);
	void find_size_of_file(std::string path);
	void change_owner(std::string username, std::string path);
	void change_group(std::string groupname, std::string path);
	void promote(std::string username,std::string new_role);
	void demote(std::string username, std::string new_role);
	void userlist();
	void show_storage();

	std::vector<User*> users;
	std::vector<Group*> groups;
	int index_of_current_user;
	std::string current_location;
	std::map<std::string, UserTypeEnum> roles;	
	std::vector<Directory*> directories;
	Directory* current_directory;
	std::string source_address;
};


#endif
