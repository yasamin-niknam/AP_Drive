#ifndef USER_CLASS
#define USER_CLASS

#include <iostream>
#include "badexception.hpp"

enum UserTypeEnum
{
	superuser,
	user,
	admin
};

class User
{
public:
	User(std::string _username, std::string _password) : username(_username), password(_password), role(user) {}
	UserTypeEnum get_role(){return role;}
	void change_role(UserTypeEnum _role){role = _role;}
	bool is_same_username(std::string _username) {return (_username == username);}
	bool check_password(std::string _password) {return (_password == password);}
	void promote(std::string new_role);
	void demote(std::string new_role);
	std::string get_username(){return username;}
private:
	std::string username;
	std::string password;
	UserTypeEnum role;
};


#endif
