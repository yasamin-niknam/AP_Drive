#ifndef __PROMOTE_HANDLER__
#define __PROMOTE_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Promote_Handler : public RequestHandler {
public:
	Interface* interface; 
	Promote_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif