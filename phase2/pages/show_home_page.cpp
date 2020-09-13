#include "show_home_page.hpp"

using namespace std;

Response* Show_Home_Page::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
	{
		string online_username = interface->get_online_username(session_id);

		res->setHeader("Content-Type", "text/html");
		string body = readFile(file_path);

		body = set_kind_of_stylesheet(body, "/home_style");
		body = set_logged_in_user(body, online_username);

		User* online_user = interface->find_online_user(session_id);
		UserTypeEnum online_user_role = online_user->get_role();
		if((online_user_role == superuser) || (online_user_role == admin))
		{
			body = show_administer_page(body, online_username);
		}
		else if(online_user_role == user)
		{
			interface->change_current_directory_name(online_username);
			vector<string> directories = interface->get_directories();
			vector<string> files = interface->get_files();
			body = show_usual_page(body, online_username, directories, files);
		}
		res->setBody(body);
	}
	else
		res = Response::redirect("/login");
	return res;
}