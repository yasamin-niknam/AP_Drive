#ifndef __BACK_DETAIL_HANDLER__
#define __BACK_DETAIL_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logic/interface.hpp"
#include "html_maker.hpp"


class Back_Detail_Handler : public RequestHandler {
public:
	Interface* interface; 
	Back_Detail_Handler(Interface* _interface) :
			interface(_interface) {}
 	Response *callback(Request *req);
};

#endif