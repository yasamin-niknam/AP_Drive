#include "show_details_handler.hpp"

using namespace std;

Response* Show_Details_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string online_username = interface->get_online_username(session_id);

		string detailed_directory = req->getBodyParam("detailed_directory");
		string detailed_file = req->getBodyParam("detailed_file");

		res->setHeader("Content-Type", "text/html");
		string body = readFile(file_path);

		body = set_kind_of_stylesheet(body, "/details_page_style");
		body = set_logged_in_user(body, online_username);
		
		string details;
		
		if(detailed_directory != "")
			details = interface->get_directory_details_by_name(detailed_directory);
		else if(detailed_file != "")
			details = interface->get_file_details_by_name(detailed_file);
		

		body = show_details_page(body, details);
		res->setBody(body);
	}
	else
		res = Response::redirect("/login");
	return res;
}