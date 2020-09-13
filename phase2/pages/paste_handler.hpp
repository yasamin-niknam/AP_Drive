#ifndef __PASTE_HANDLER__
#define __PASTE_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Paste_Handler : public RequestHandler {
public:
	Interface* interface; 
	Paste_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif