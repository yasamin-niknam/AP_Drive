#include "user.hpp"

using namespace std;

void User::promote()
{
	if(role == user)
		role = admin;
	else if(role == admin)
		role = superuser;
	else
		throw BadException("This user is SuperUser");
}

void User::demote()
{
	if(role == admin)
		role = user;
	else if(role == superuser)
		role = admin;
	else
		throw BadException("This user is already a normal user");
}