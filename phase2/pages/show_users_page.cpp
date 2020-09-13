#include "show_users_page.hpp"

using namespace std;

Response* Show_Users_Page::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string online_username = interface->get_online_username(session_id);

		res->setHeader("Content-Type", "text/html");
		string body = readFile(file_path);

		body = set_kind_of_stylesheet(body, "/users_page_style");
		body = set_logged_in_user(body, online_username);

		vector<string> usernames = interface->get_usernames();
		body = show_users_page(body, usernames);
		res->setBody(body);
	}
	else
		res = Response::redirect("/login");
	return res;
}