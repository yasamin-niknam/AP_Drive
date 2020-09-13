#include "paste_handler.hpp"

using namespace std;

Response* Paste_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		res->setHeader("Content-Type", "text/html");
		interface->add_copied_element();

		res = Response::redirect("/show_elements");
	}
	else
		res = Response::redirect("/login");
	return res;
}