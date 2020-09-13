#include "login_handler.hpp"

using namespace std;

Response* Login_Handler::callback(Request *req) 
{
	Response *res = new Response;
	string username = req->getBodyParam("username");
	string password = req->getBodyParam("password");
	res->setHeader("Content-Type", "text/html");
	try{
		int random_number = rand(); 
		interface->login(username, password);
		interface->set_session_id(username, random_number);
		string s_random_number = to_string(random_number);
		res = Response::redirect("/home");
		res->setSessionId(s_random_number);
	}
	catch(BadException ex)
	{
		res = Response::redirect("/login_with_error");
	}
	return res;
}