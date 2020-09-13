#ifndef __ADD_DIRECTORY_HANDLER__
#define __ADD_DIRECTORY_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Add_Directory_Handler : public RequestHandler {
public:
	Interface* interface; 
	Add_Directory_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif