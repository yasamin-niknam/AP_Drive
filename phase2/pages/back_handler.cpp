#include "back_handler.hpp"

using namespace std;

Response* Back_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string online_username = interface->get_online_username(session_id);
		User* online_user = interface->find_online_user(session_id);
		UserTypeEnum online_user_role = online_user->get_role();

		res->setHeader("Content-Type", "text/html");
		
		if(online_user_role != user)
		{
			if(interface->go_back())
					res = Response::redirect("/show_elements");
			else 
				res = Response::redirect("/home");
		}
		else
		{
			if(interface->usual_user_can_go_back(online_username))
			{
				interface->go_back();
				res = Response::redirect("/show_elements");
			}
			else
				res = Response::redirect("/home");

		}	
	}
	else
		res = Response::redirect("/login");
	return res;
}