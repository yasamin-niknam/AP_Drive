#ifndef __DEMOTE_HANDLER__
#define __DEMOTE_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Demote_Handler : public RequestHandler {
public:
	Interface* interface; 
	Demote_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif