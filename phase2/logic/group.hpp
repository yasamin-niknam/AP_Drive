#ifndef GROUP_CLASS
#define GROUP_CLASS

#include <iostream>
#include <vector>
#include "user.hpp"

class Group
{
public:
	Group(std::string _owner_username, std::string _group_name);
	bool is_same_group(std::string _group_name){return (group_name == _group_name);}
	void add_user(std::string username){members.push_back(username);}
	bool is_in_group(std::string name);
private:
	std::string owner_username;
	std::string group_name;
	std::vector<std::string> members;
};


#endif

