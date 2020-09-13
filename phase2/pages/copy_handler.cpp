#include "copy_handler.hpp"

using namespace std;

Response* Copy_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string copied_directory = req->getBodyParam("copied_directory");
		string copied_file = req->getBodyParam("copied_file");
		string online_username = interface->get_online_username(session_id);
		res->setHeader("Content-Type", "text/html");
		if(copied_directory != "")
		{
			try
			{
				interface->make_copy_directory(copied_directory);
			}
			catch(BadException ex)
			{
				res = Response::redirect("/show_elements");
			}
		}
		else if(copied_file != "")
		{
			try
			{
				interface->make_copy_file(copied_file);
			}
			catch(BadException ex)
			{
				res = Response::redirect("/show_elements");
			}
		}
		res = Response::redirect("/show_elements");
	}
	else
		res = Response::redirect("/login");
	return res;
}