#ifndef __LOGOUT__
#define __LOGOUT__

#include <iostream>
#include <string>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"

class Logout : public RequestHandler {
	Interface* interface; 
public:
	Logout(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};
#endif