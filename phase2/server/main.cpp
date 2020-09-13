#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../pages/logout.hpp"
#include "../logic/interface.hpp"
#include "../pages/move_handler.hpp"
#include "../pages/paste_handler.hpp"
#include "../pages/back_handler.hpp"
#include "../pages/copy_handler.hpp"
#include "../pages/login_handler.hpp"
#include "../pages/remove_handler.hpp"
#include "../pages/demote_handler.hpp"
#include "../pages/show_home_page.hpp"
#include "../pages/show_login_page.hpp"
#include "../pages/promote_handler.hpp"
#include "../pages/show_users_page.hpp"
#include "../pages/add_user_handler.hpp"
#include "../pages/show_elements_page.hpp"
#include "../pages/back_detail_handler.hpp"
#include "../pages/show_details_handler.hpp"
#include "../pages/add_directory_handler.hpp"
#include "../pages/next_directory_handler.hpp"


using namespace std;

int main(int argc, char **argv)
{
	srand (time(NULL));
	
    Interface interface = Interface("/mnt/c/Users/ASUS/Desktop/term5/AP/CA4/A");
    interface.initial_files();

	Server server(argc > 1 ? atoi(argv[1]) : 5000);

    server.get("/global_style", new ShowPage("static/styles/global_styles.css"));

    server.get("/login", new Show_Login_Page(&interface, "static/login.html")); 
    server.post("/login", new Login_Handler(&interface));
    server.get("/login_style", new ShowPage("static/styles/login_style.css"));

    server.get("/login_with_error", new ShowPage("static/login_with_error.html"));
    server.get("/login_with_error_style", new ShowPage("static/styles/login_with_error_style.css"));

    server.get("/home", new Show_Home_Page(&interface, "static/home.html"));
    server.get("/home_style", new ShowPage("static/styles/home_style.css"));

    server.get("/show_users", new Show_Users_Page(&interface, "static/home.html"));
    server.post("/add_user", new Add_User_Handler(&interface));
    server.post("/promote", new Promote_Handler(&interface));
    server.post("/demote", new Demote_Handler(&interface));
    
    server.post("/detailed_element", new Show_Details_Handler(&interface, "static/home.html"));
    server.post("/back_details", new Back_Detail_Handler(&interface));
    
    server.get("/drive_logo", new ShowImage("static/images/drive_icon.png"));

    server.get("/show_elements", new Show_Elements_Page(&interface, "static/home.html"));
    server.post("/add_directory", new Add_Directory_Handler(&interface));
    server.post("/copy_element", new Copy_Handler(&interface));
    server.post("/move_element", new Move_Handler(&interface));
    server.post("/remove_element", new Remove_Handler(&interface));
    server.post("/next_directory", new Next_Directory_Handler(&interface));
    server.post("/paste", new Paste_Handler(&interface));
    
    server.post("/back", new Back_Handler(&interface));

    server.post("/logout", new Logout(&interface));

    server.run();
	return 0;
}