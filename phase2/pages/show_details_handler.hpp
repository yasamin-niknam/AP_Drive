#ifndef __SHOW_DETAILS_HANDLER__
#define __SHOW_DETAILS_HANDLER__

#include <iostream>
#include <string>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"

class Show_Details_Handler : public RequestHandler {
public:
	Interface* interface; 
	std::string file_path;
	Show_Details_Handler(Interface* _interface, std::string _file_path) :
			interface(_interface), file_path(_file_path) {}
 	Response *callback(Request *req);
};
#endif