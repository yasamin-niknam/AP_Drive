#ifndef __SHOW_LOGIN_PAGE__
#define __SHOW_LOGIN_PAGE__

#include <iostream>
#include <string>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"

class Show_Login_Page : public RequestHandler {
	Interface* interface; 
	std::string file_path;
public:
	Show_Login_Page(Interface* _interface, std::string _file_path) :
			interface(_interface), file_path(_file_path) {}
 	Response *callback(Request *req);
};
#endif