#include "promote_handler.hpp"

using namespace std;

Response* Promote_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string username = req->getBodyParam("promoted_name");
		string online_username = interface->get_online_username(session_id);
		res->setHeader("Content-Type", "text/html");
		try
		{
			interface->promote(username);
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