#ifndef __MOVE_HANDLER__
#define __MOVE_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Move_Handler : public RequestHandler {
public:
	Interface* interface; 
	Move_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif