#include "logout.hpp"

using namespace std;

Response* Logout::callback(Request *req) 
{
	int session_id = atoi((req->getSessionId()).c_str());
	interface->logout(session_id);
	Response* res = Response::redirect("/login");
	return res;
}