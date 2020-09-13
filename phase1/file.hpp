#ifndef FILE_CLASS
#define FILE_CLASS

#include <iostream>
#include <vector>
#include "element.hpp"

class Directory;

class File : public Element
{
public:
	File(std::string _name, std::string _path, std::string _owner_username) : Element(_name, _path, _owner_username) {}
	void copy_file(File* destination);
	void move(Directory* destination);
	void change_info(std::vector<char> new_info);
	int show_size();
	int size(){return information.size() / 1000;}
	std::vector<char> get_info(){return information;}
private:
	std::vector<char> information;
	
};


#endif

