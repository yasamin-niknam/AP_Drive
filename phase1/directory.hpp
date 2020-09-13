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
	void remove_file(File* file);
	void move_file(File* file);
	void insert_file(File* new_file);
	File* find_file(std::string file_name);
	void copy_directory(Directory* destination);
	void remove_directory(Directory* directory);
	Directory* find_directory(std::string directory_name);
	Directory* add_directory(std::string directory_name, std::string path, std::string username);
	int calc_storage();
private:
	std::vector<Directory*> directories;
	std::vector<File*> files;
};

#endif

