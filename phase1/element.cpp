#include "element.hpp"

using namespace std;

Element::Element(string _name, string _path, string _owner_username)
{
	name = _name;
	path = _path;
	owner_username = _owner_username;
	owner_group = _owner_username;
}

bool Element::is_same_element(string _name)
{
	return (_name == name);
}

string Element::show_owner_permissions()
{
	if(owner_permissions.read && owner_permissions.write)
		return "read,write";
	else if(owner_permissions.read)
		return "read,-";
	else if(owner_permissions.write)
		return "write,-";
	else
		return "-,-";
}
string Element::show_group_permissions()
{
	if(group_permissions.read && group_permissions.write)
		return "read,write";
	else if(group_permissions.read)
		return "read,-";
	else if(group_permissions.write)
		return "write,-";
	else
		return "-,-";
}

void Element::elem_info(string type)
{
	cout << type << " " << show_owner_permissions() << " " << 
		show_group_permissions() << " " << owner_username << " " << owner_group << " " << name << endl;
}

void Element::change_mode(string group_or_user, string plus_or_minus, string permissions)
{
	if(group_or_user == "group")
	{
		if(plus_or_minus == "+")
		{
			if(permissions == "read")
				group_permissions.read = true;
			else if(permissions == "write")
				group_permissions.write = true;
			else if(permissions == "rw")
			{
				group_permissions.read = true;
				group_permissions.write = true;
			}
		}
		else if(plus_or_minus == "-")
		{
			if(permissions == "read")
				group_permissions.read = false;
			else if(permissions == "write")
				group_permissions.write = false;
			else if(permissions == "rw")
			{
				group_permissions.read = false;
				group_permissions.write = false;
			}
		}
	}
	else if(group_or_user == "user")
	{
		if(plus_or_minus == "+")
		{
			if(permissions == "read")
				owner_permissions.read = true;
			else if(permissions == "write")
				owner_permissions.write = true;
			else if(permissions == "rw")
			{
				owner_permissions.read = true;
				owner_permissions.write = true;
			}
		}
		else if(plus_or_minus == "-")
		{
			if(permissions == "read")
				owner_permissions.read = false;
			else if(permissions == "write")
				owner_permissions.write = false;
			else if(permissions == "rw")
			{
				owner_permissions.read = false;
				owner_permissions.write = false;
			}
		}
	}
}
