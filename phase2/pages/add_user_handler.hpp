#ifndef __ADD_USER_HANDLER__
#define __ADD_USER_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Add_User_Handler : public RequestHandler {
public:
	Interface* interface; 
	Add_User_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif