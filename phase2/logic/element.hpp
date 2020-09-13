#ifndef ELEMENT_CLASS
#define ELEMENT_CLASS

#include <iostream>

struct Permission
{
	bool read = false;
	bool write = false;
};

class Element
{
public:
	Element(std::string _name, std::string _path, std::string _owner_username);
	virtual bool is_same_element(std::string _name);
	virtual std::string show_owner_permissions();
	virtual std::string show_group_permissions();
	virtual void elem_info(std::string type);
	virtual bool is_owner(std::string username){return (owner_username == username);}
	virtual void change_owner(std::string username){owner_username = username;}
	virtual void change_group(std::string groupname){owner_group = groupname;}
	virtual void change_mode(std::string group_or_user, std::string plus_or_minus, std::string permissions);
	virtual std::string get_path(){return path;}
	virtual std::string get_name(){return name;}
	virtual std::string get_owner_user(){return owner_username;}
	virtual std::string get_owner_group(){return owner_group;}
protected:
	std::string name;
	std::string path;
	std::string owner_username;
	Permission owner_permissions;
	std::string owner_group;
	Permission group_permissions;
};


#endif

