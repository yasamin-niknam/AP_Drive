#ifndef __SHOW_USERS_PAGE__
#define __SHOW_USERS_PAGE__

#include <iostream>
#include <string>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"

class Show_Users_Page : public RequestHandler {
	Interface* interface; 
	std::string file_path;
public:
	Show_Users_Page(Interface* _interface, std::string _file_path) :
			interface(_interface), file_path(_file_path) {}
 	Response *callback(Request *req);
};
#endif