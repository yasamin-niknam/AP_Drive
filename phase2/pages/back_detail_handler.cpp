#include "back_detail_handler.hpp"

using namespace std;

Response* Back_Detail_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		res->setHeader("Content-Type", "text/html");		
		res = Response::redirect("/show_elements");	
	}
	else
		res = Response::redirect("/login");
	return res;
}