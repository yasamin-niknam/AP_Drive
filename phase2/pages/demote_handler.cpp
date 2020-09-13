#include "demote_handler.hpp"

using namespace std;

Response* Demote_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string username = req->getBodyParam("demoted_name");
		res->setHeader("Content-Type", "text/html");
		try
		{
			interface->demote(username);
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