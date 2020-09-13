#ifndef __LOGIN_HANDLER__
#define __LOGIN_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"

class Login_Handler : public RequestHandler {
public:
	Interface* interface; 
	Login_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif