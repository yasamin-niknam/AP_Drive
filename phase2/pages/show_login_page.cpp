#include "show_login_page.hpp"

using namespace std;

Response* Show_Login_Page::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(interface->check_session_id(session_id))
		res = Response::redirect("/home");
	else
	{
		res->setHeader("Content-Type", "text/html");
		string body = readFile(file_path);
		res->setBody(body);
	}
	return res;
}