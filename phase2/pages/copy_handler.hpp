#ifndef __COPY_HANDLER__
#define __COPY_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Copy_Handler : public RequestHandler {
public:
	Interface* interface; 
	Copy_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif