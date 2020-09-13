#include "add_user_handler.hpp"

using namespace std;

Response* Add_User_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string username = req->getBodyParam("username");
		string password = req->getBodyParam("password");
		string online_username = interface->get_online_username(session_id);
		res->setHeader("Content-Type", "text/html");
		try
		{
			interface->add_user(username, password);
		}
		catch(BadException ex)
		{
			res = Response::redirect("/show_users");
		}
		res = Response::redirect("/show_users");
	}
	else
		res = Response::redirect("/login");
	return res;
}