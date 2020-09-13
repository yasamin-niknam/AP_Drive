#include "group.hpp"

using namespace std;

Group::Group(string _owner_username, string _group_name)
{
	owner_username = _owner_username;
	group_name = _group_name;
	members.push_back(owner_username);
}

bool Group::is_in_group(string name)
{
	for (int i = 0; i < members.size(); ++i)
	{
		if(name == members[i])
			return true;
	}
	return false;
}
