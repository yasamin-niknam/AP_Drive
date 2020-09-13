#include "remove_handler.hpp"

using namespace std;

Response* Remove_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string removed_directory = req->getBodyParam("removed_directory");
		string removed_file = req->getBodyParam("removed_file");
		string online_username = interface->get_online_username(session_id);
		res->setHeader("Content-Type", "text/html");
		
		if(removed_directory != "")
			interface->remove_directory_by_name(removed_directory);
		else if(removed_file != "")
			interface->remove_file_by_name(removed_file);
		
		res = Response::redirect("/show_elements");
	}
	else
		res = Response::redirect("/login");
	return res;
}