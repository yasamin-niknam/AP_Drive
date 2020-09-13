#include "add_directory_handler.hpp"

using namespace std;

Response* Add_Directory_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string directory_name = req->getBodyParam("directory_name");
		res->setHeader("Content-Type", "text/html");
		try
		{
			string online_username = interface->get_online_username(session_id);
			interface->make_directory(directory_name, online_username);	
		}
		catch(BadException ex)
		{
			res = Response::redirect("/show_elements");
		}
		res = Response::redirect("/show_elements");
	}
	else
		res = Response::redirect("/login");
	return res;
}