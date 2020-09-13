#include "next_directory_handler.hpp"

using namespace std;

Response* Next_Directory_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string next_directory = req->getBodyParam("next_directory");
		string online_username = interface->get_online_username(session_id);
		res->setHeader("Content-Type", "text/html");
		
		interface->change_current_directory_name(next_directory);
		res = Response::redirect("/show_elements");
	}
	else
		res = Response::redirect("/login");
	return res;
}