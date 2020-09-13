#include "html_maker.hpp"

using namespace std;

string set_logged_in_user(string base_string, string display_name)
{
	string body;
	string s = "<!--display_name-->";
	int index_of_content_flag = base_string.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string second_part = base_string.substr(first_index_of_second_part);
	string first_part = base_string.substr(0, first_index_of_second_part);

	body = first_part;
	body += display_name;
	body += second_part;
	return body;
}
string set_kind_of_stylesheet(string base_string, string style_path)
{
	string body;
	string s = "<title>AP Drive</title>";
	int index_of_content_flag = base_string.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string second_part = base_string.substr(first_index_of_second_part);
	string first_part = base_string.substr(0, first_index_of_second_part);

	body = first_part;
	body += "<link rel=\"stylesheet\" href=\"";
	body += style_path;
	body += "\">";
	body += second_part;
	return body;
}

string show_administer_page(string base_body, string online_username)
{
	string body;
	string s = "<div class=\"the_content\">";
	int index_of_content_flag = base_body.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string first_part = base_body.substr(0, first_index_of_second_part);
	string second_part = base_body.substr(first_index_of_second_part);
	body = first_part;
	
	body += "<div>";
	body += "<p><a href=\"/show_users\">Show Users</a></p>";
	body += "<p><a href=\"/show_elements\">Show Elements</a></p>";
	body += "</div>";

	body += second_part;
	
	return body;
}

string show_usual_page(string base_body, string online_username, vector<string> directories, vector<string> files)
{
	string body;
	string s = "<div class=\"the_content\">";
	int index_of_content_flag = base_body.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string first_part = base_body.substr(0, first_index_of_second_part);
	string second_part = base_body.substr(first_index_of_second_part);
	body = first_part;

	body += "<div><p>";
	body += "<form action=\"/add_directory\" method=\"post\">";
	body += "<button class=\"btn_add_directory\" type=\"submit\"> Add Directory </button>";
    body += "<input class=\"input\" name=\"directory_name\" type=\"text\" placeholder=\"Directory Name\"/>";
    body += "<span  class=\"input_border\"></span>";
    body += "</form>";
	body += "</p></div>";

	body += "<div>";
	for (int i = 0; i < directories.size(); ++i)
	{
		body += "<p>";
		body += directories[i];
		body += "<form action=\"/remove_element\" method=\"post\"><input type=\"hidden\" name=\"removed_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_remove\" type=\"post\"> Remove</button>";
	    body += "</form>";

	    body += "<form action=\"/next_directory\" method=\"post\"><input type=\"hidden\" name=\"next_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_next\" type=\"post\"> Go </button>";
	    body += "</form>";
		
		body += "<form action=\"/copy_element\" method=\"post\"><input type=\"hidden\" name=\"copied_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_copy\" type=\"post\"> Copy</button>";
	    body += "</form>";
		
		body += "<form action=\"/move_element\" method=\"post\"><input type=\"hidden\" name=\"moved_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_move\" type=\"post\"> Move</button>";
    	body += "</form>";
		body += "</p>";
	}

	body += "</div>";
	body += "<div>";
		
	for (int i = 0; i < files.size(); ++i)
	{
		body += "<p>";
		body += files[i];
		body += "<form action=\"/remove_element\" method=\"post\"><input type=\"hidden\" name=\"removed_file\" value=\"";
		body += files[i];
		body += "\"><button class=\"btn_remove\" type=\"post\"> Remove</button>";
	    body += "</form>";
		body += "<form action=\"/copy_element\" method=\"post\"><input type=\"hidden\" name=\"copied_file\" value=\"";
		body += files[i];
		body += "\"><button class=\"btn_copy\" type=\"post\"> Copy</button>";
	    body += "</form>";
		body += "<form action=\"/move_element\" method=\"post\"><input type=\"hidden\" name=\"moved_file\" value=\"";
		body += files[i];
		body += "\"><button class=\"btn_move\" type=\"post\"> Move</button>";
    	body += "</form>";
		body += "</p>";
	}
	body += "</div>";
	
	body += second_part;
	
	return body;
}

string show_users_page(string base_body, vector<string> usernames)
{
	string body;
	string s = "<div class=\"the_content\">";
	int index_of_content_flag = base_body.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string first_part = base_body.substr(0, first_index_of_second_part);
	string second_part = base_body.substr(first_index_of_second_part);
	body = first_part;
	
	body += "<div><p>";
	body += "<form action=\"/back\" method=\"post\">";
	body += "<button class=\"btn_back\" type=\"submit\"> Back </button>";
    body += "</form>";
	body += "</p></div>";

	body += "<div><p>";
	body += "<form action=\"/add_user\" method=\"post\">";
	body += "<button class=\"btn_add_user\" type=\"submit\"> Add User </button>";
    body += "<input class=\"username_input\" name=\"username\" type=\"text\" placeholder=\"Username\"/>";
    body += "<span  class=\"input_border\"></span>";
    body += "<input class=\"username_input\" name=\"password\" type=\"text\" placeholder=\"Password\"/>";
    body += "<span  class=\"input_border\"></span>";
    body += "</form>";
	body += "</p></div>";
	
	body += "<div class=\"user_info\">";
	
	for (int i = 0; i < usernames.size(); ++i)
	{
		body += "<p class=\"show_username\">";
		body += usernames[i];
		body += "<form action=\"/promote\" method=\"post\"><input type=\"hidden\" name=\"promoted_name\" value=\"";
		body += usernames[i];
		body += "\"><button class=\"btn_promote\" type=\"submit\"> Promote</button></form>";
		body += "<form action=\"/demote\" method=\"post\"><input type=\"hidden\" name=\"demoted_name\" value=\"";
		body += usernames[i];
		body += "\"><button class=\"btn_demote\" type=\"submit\"> Demote</button></form>";
		body += "</p>";
	}
	body += "</div>";
	
	body += second_part;
	
	return body;	
}

string show_elements_page(string base_body, vector<string> directories, vector<string> files)
{
	string body;
	string s = "<div class=\"the_content\">";
	int index_of_content_flag = base_body.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string first_part = base_body.substr(0, first_index_of_second_part);
	string second_part = base_body.substr(first_index_of_second_part);
	body = first_part;
	
	body += "<div><p>";
	body += "<form action=\"/back\" method=\"post\">";
	body += "<button class=\"btn_back\" type=\"submit\"> Back </button>";
    body += "</form>";
	body += "</p></div>";

	body += "<div><p>";
	body += "<form action=\"/paste\" method=\"post\">";
	body += "<button class=\"btn_paste\" type=\"submit\"> Paste </button>";
    body += "</form>";
	body += "</p></div>";

	body += "<div><p>";
	body += "<form action=\"/add_directory\" method=\"post\">";
	body += "<button class=\"btn_add_directory\" type=\"submit\"> Add Directory </button>";
    body += "<input class=\"input\" name=\"directory_name\" type=\"text\" placeholder=\"Directory Name\"/>";
    body += "<span  class=\"input_border\"></span>";
    body += "</form>";
	body += "</p></div>";

	body += "<div>";
	if(directories.size() > 0)
		body += "<p>Directories:</p>";
	for (int i = 0; i < directories.size(); ++i)
	{
		body += "<p>";
		body += directories[i];
		body += "<form action=\"/remove_element\" method=\"post\"><input type=\"hidden\" name=\"removed_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_remove\" type=\"post\"> Remove</button>";
	    body += "</form>";

	    body += "<form action=\"/next_directory\" method=\"post\"><input type=\"hidden\" name=\"next_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_next\" type=\"post\"> Go </button>";
	    body += "</form>";
		
	    body += "<form action=\"/detailed_element\" method=\"post\"><input type=\"hidden\" name=\"detailed_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_details\" type=\"post\"> Details </button>";
	    body += "</form>";

		body += "<form action=\"/copy_element\" method=\"post\"><input type=\"hidden\" name=\"copied_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_copy\" type=\"post\"> Copy </button>";
	    body += "</form>";
		
		body += "<form action=\"/move_element\" method=\"post\"><input type=\"hidden\" name=\"moved_directory\" value=\"";
		body += directories[i];
		body += "\"><button class=\"btn_move\" type=\"post\"> Move</button>";
    	body += "</form>";
		body += "</p>";
	}
	body += "</div>";

	body += "<div>";
	if(files.size() > 0)
		body += "<p>Files:</p>";
	for (int i = 0; i < files.size(); ++i)
	{
		body += "<p>";
		body += files[i];
		body += "<form action=\"/remove_element\" method=\"post\"><input type=\"hidden\" name=\"removed_file\" value=\"";
		body += files[i];
		body += "\"><button class=\"btn_remove\" type=\"post\"> Remove</button>";
	    body += "</form>";

		body += "<form action=\"/detailed_element\" method=\"post\"><input type=\"hidden\" name=\"detailed_file\" value=\"";
		body += files[i];
		body += "\"><button class=\"btn_details\" type=\"post\"> Details </button>";
	    body += "</form>";

		body += "<form action=\"/copy_element\" method=\"post\"><input type=\"hidden\" name=\"copied_file\" value=\"";
		body += files[i];
		body += "\"><button class=\"btn_copy\" type=\"post\"> Copy</button>";
	    body += "</form>";
		
		body += "<form action=\"/move_element\" method=\"post\"><input type=\"hidden\" name=\"moved_file\" value=\"";
		body += files[i];
		body += "\"><button class=\"btn_move\" type=\"post\"> Move</button>";
    	body += "</form>";
		body += "</p>";
	}
	body += "</div>";
	
	body += second_part;
	
	return body;	
}

string show_details_page(string base_body, string details)
{
	string body;
	string s = "<div class=\"the_content\">";
	int index_of_content_flag = base_body.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string first_part = base_body.substr(0, first_index_of_second_part);
	string second_part = base_body.substr(first_index_of_second_part);
	body = first_part;
	
	body += "<div><p>";
	body += "<form action=\"/back_details\" method=\"post\">";
	body += "<button class=\"btn_back_details\" type=\"submit\"> Back </button>";
    body += "</form>";
	body += "</p></div>";

	body += "<div><p>";
	body += details;
	body += "</p></div>";
	
	body += second_part;
	return body;	
}