#ifndef __HTML_MAKER__
#define __HTML_MAKER__

#include <iostream>
#include <string>
#include "../logic/interface.hpp"

std::string show_administer_page(std::string base_body, std::string online_username);
std::string show_usual_page(std::string base_body, std::string online_username, std::vector<std::string> directories, std::vector<std::string> files);

std::string set_logged_in_user(std::string base_string, std::string display_name);
std::string set_kind_of_stylesheet(std::string base_string, std::string style_path);

std::string show_users_page(std::string base_body, std::vector<std::string> usernames);
std::string show_elements_page(std::string base_body, std::vector<std::string> directories, std::vector<std::string> files);
std::string show_details_page(std::string base_body, std::string details);

#endif