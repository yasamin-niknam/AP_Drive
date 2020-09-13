#include "user.hpp"

using namespace std;

void User::promote(string new_role)
{
	if(new_role == "superuser")
		role = superuser;
	else if(new_role == "admin")
		role = admin;
	else
		throw BadException("This user is already a SuperUser");
}

void User::demote(string new_role)
{
	if(new_role == "normal")
		role = user;
	else if(new_role == "admin")
		role = admin;
	else
		throw BadException("This user is already a normal user");
}