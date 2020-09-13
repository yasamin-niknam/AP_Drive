CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build

all: $(BUILD_DIR) server.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/interface.o: logic/interface.cpp logic/interface.hpp logic/user.hpp logic/badexception.hpp logic/group.hpp logic/directory.hpp logic/file.hpp
	$(CC) $(CF) -c logic/interface.cpp -o $(BUILD_DIR)/interface.o

$(BUILD_DIR)/user.o: logic/user.cpp logic/user.hpp
	$(CC) $(CF) -c logic/user.cpp -o $(BUILD_DIR)/user.o

$(BUILD_DIR)/group.o: logic/group.cpp logic/group.hpp logic/user.hpp
	$(CC) $(CF) -c logic/group.cpp -o $(BUILD_DIR)/group.o

$(BUILD_DIR)/element.o: logic/element.cpp logic/element.hpp
	$(CC) $(CF) -c logic/element.cpp -o $(BUILD_DIR)/element.o

$(BUILD_DIR)/directory.o: logic/directory.cpp logic/directory.hpp logic/file.hpp logic/element.hpp
	$(CC) $(CF) -c logic/directory.cpp -o $(BUILD_DIR)/directory.o

$(BUILD_DIR)/file.o: logic/file.cpp logic/file.hpp logic/element.hpp 
	$(CC) $(CF) -c logic/file.cpp -o $(BUILD_DIR)/file.o

$(BUILD_DIR)/badexception.o: logic/badexception.cpp logic/badexception.hpp
	$(CC) $(CF) -c logic/badexception.cpp -o $(BUILD_DIR)/badexception.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/login_handler.o: pages/login_handler.cpp pages/login_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/login_handler.cpp -o $(BUILD_DIR)/login_handler.o

$(BUILD_DIR)/copy_handler.o: pages/copy_handler.cpp pages/copy_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/copy_handler.cpp -o $(BUILD_DIR)/copy_handler.o

$(BUILD_DIR)/paste_handler.o: pages/paste_handler.cpp pages/paste_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/paste_handler.cpp -o $(BUILD_DIR)/paste_handler.o

$(BUILD_DIR)/move_handler.o: pages/move_handler.cpp pages/move_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/move_handler.cpp -o $(BUILD_DIR)/move_handler.o

$(BUILD_DIR)/back_handler.o: pages/back_handler.cpp pages/back_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/back_handler.cpp -o $(BUILD_DIR)/back_handler.o

$(BUILD_DIR)/back_detail_handler.o: pages/back_detail_handler.cpp pages/back_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/back_detail_handler.cpp -o $(BUILD_DIR)/back_detail_handler.o

$(BUILD_DIR)/show_details_handler.o: pages/show_details_handler.cpp pages/show_details_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/show_details_handler.cpp -o $(BUILD_DIR)/show_details_handler.o

$(BUILD_DIR)/remove_handler.o: pages/remove_handler.cpp pages/remove_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/remove_handler.cpp -o $(BUILD_DIR)/remove_handler.o

$(BUILD_DIR)/promote_handler.o: pages/promote_handler.cpp pages/promote_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/promote_handler.cpp -o $(BUILD_DIR)/promote_handler.o

$(BUILD_DIR)/demote_handler.o: pages/demote_handler.cpp pages/demote_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/demote_handler.cpp -o $(BUILD_DIR)/demote_handler.o

$(BUILD_DIR)/add_directory_handler.o: pages/add_directory_handler.cpp pages/add_directory_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/add_directory_handler.cpp -o $(BUILD_DIR)/add_directory_handler.o

$(BUILD_DIR)/next_directory_handler.o: pages/next_directory_handler.cpp pages/add_directory_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/next_directory_handler.cpp -o $(BUILD_DIR)/next_directory_handler.o

$(BUILD_DIR)/add_user_handler.o: pages/add_user_handler.cpp pages/add_user_handler.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/add_user_handler.cpp -o $(BUILD_DIR)/add_user_handler.o

$(BUILD_DIR)/show_home_page.o: pages/show_home_page.cpp pages/show_home_page.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp pages/html_maker.hpp
	$(CC) $(CF) -c pages/show_home_page.cpp -o $(BUILD_DIR)/show_home_page.o

$(BUILD_DIR)/show_users_page.o: pages/show_users_page.cpp pages/show_users_page.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp pages/html_maker.hpp
	$(CC) $(CF) -c pages/show_users_page.cpp -o $(BUILD_DIR)/show_users_page.o

$(BUILD_DIR)/show_elements_page.o: pages/show_elements_page.cpp pages/show_elements_page.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp pages/html_maker.hpp
	$(CC) $(CF) -c pages/show_elements_page.cpp -o $(BUILD_DIR)/show_elements_page.o

$(BUILD_DIR)/show_login_page.o: pages/show_login_page.cpp pages/show_login_page.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp server/server.hpp logic/interface.hpp
	$(CC) $(CF) -c pages/show_login_page.cpp -o $(BUILD_DIR)/show_login_page.o

$(BUILD_DIR)/html_maker.o: pages/html_maker.cpp pages/html_maker.hpp $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/html_maker.cpp -o $(BUILD_DIR)/html_maker.o

$(BUILD_DIR)/logout.o: pages/logout.cpp pages/logout.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/logout.cpp -o $(BUILD_DIR)/logout.o

$(BUILD_DIR)/main.o: server/main.cpp $(BUILD_DIR)/server.o  $(BUILD_DIR)/interface.o $(BUILD_DIR)/login_handler.o $(BUILD_DIR)/show_login_page.o $(BUILD_DIR)/show_home_page.o $(BUILD_DIR)/html_maker.o $(BUILD_DIR)/add_directory_handler.o $(BUILD_DIR)/logout.o
	$(CC) $(CF) -c server/main.cpp -o $(BUILD_DIR)/main.o

server.out: $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/main.o $(BUILD_DIR)/login_handler.o $(BUILD_DIR)/paste_handler.o $(BUILD_DIR)/back_detail_handler.o $(BUILD_DIR)/back_handler.o $(BUILD_DIR)/show_details_handler.o $(BUILD_DIR)/copy_handler.o $(BUILD_DIR)/remove_handler.o $(BUILD_DIR)/move_handler.o $(BUILD_DIR)/promote_handler.o $(BUILD_DIR)/demote_handler.o $(BUILD_DIR)/add_directory_handler.o $(BUILD_DIR)/next_directory_handler.o $(BUILD_DIR)/add_user_handler.o $(BUILD_DIR)/logout.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/directory.o $(BUILD_DIR)/file.o $(BUILD_DIR)/badexception.o $(BUILD_DIR)/element.o $(BUILD_DIR)/group.o $(BUILD_DIR)/user.o $(BUILD_DIR)/show_login_page.o $(BUILD_DIR)/show_home_page.o $(BUILD_DIR)/show_elements_page.o $(BUILD_DIR)/show_users_page.o $(BUILD_DIR)/html_maker.o
	$(CC) $(CF) $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/main.o $(BUILD_DIR)/login_handler.o $(BUILD_DIR)/paste_handler.o $(BUILD_DIR)/back_detail_handler.o $(BUILD_DIR)/back_handler.o $(BUILD_DIR)/show_details_handler.o $(BUILD_DIR)/copy_handler.o $(BUILD_DIR)/remove_handler.o $(BUILD_DIR)/move_handler.o $(BUILD_DIR)/promote_handler.o $(BUILD_DIR)/demote_handler.o $(BUILD_DIR)/add_directory_handler.o $(BUILD_DIR)/next_directory_handler.o $(BUILD_DIR)/add_user_handler.o $(BUILD_DIR)/logout.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/directory.o $(BUILD_DIR)/file.o $(BUILD_DIR)/badexception.o $(BUILD_DIR)/element.o $(BUILD_DIR)/group.o $(BUILD_DIR)/user.o $(BUILD_DIR)/show_login_page.o $(BUILD_DIR)/show_home_page.o $(BUILD_DIR)/show_elements_page.o $(BUILD_DIR)/show_users_page.o $(BUILD_DIR)/html_maker.o -o server.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out &> /dev/null
