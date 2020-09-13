#ifndef DIRECTORY_CLASS
#define DIRECTORY_CLASS

#include <iostream>
#include <vector>
#include "element.hpp"
#include "file.hpp"
#include "badexception.hpp"

class Directory : public Element
{
public:
	Directory(std::string _name, std::string _path, std::string _owner_username);
	void clean();
	bool remove_file(File* file);
	bool move_file(File* file);
	void insert_file(File* new_file);
	void insert_directory(Directory* new_directory);
	File* find_file(std::string file_name);
	std::vector<std::string> get_file_names();
	File* find_file_rec(std::string file_name);
	void copy_directory(Directory* destination);
	bool remove_directory(Directory* directory);
	void remove_directory_from_list(Directory* directory);
	void remove_file_from_list(File* file);
	Directory* find_directory(std::string directory_name);
	Directory* find_directory_rec(std::string directory_name);
	Directory* add_directory(std::string directory_name, std::string path, std::string username);
	int calc_storage();
	bool remove_file_rec(std::string file_name);
	bool remove_directory_rec(std::string directory);
	std::vector<std::string> get_directories();
private:
	std::vector<Directory*> directories;
	std::vector<File*> files;
};

#endif
