#ifndef __REMOVE_HANDLER__
#define __REMOVE_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Remove_Handler : public RequestHandler {
public:
	Interface* interface; 
	Remove_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif