a.out: main.o interface.o user.o badexception.o group.o file.o element.o directory.o
	g++ main.o interface.o user.o badexception.o group.o file.o element.o directory.o

main.o: main.cpp interface.o 
	g++ -c main.cpp -o main.o 

interface.o: interface.cpp interface.hpp user.o badexception.o group.o directory.o file.o
	g++ -c interface.cpp -o interface.o

user.o: user.cpp user.hpp 
	g++ -c user.cpp -o user.o

badexception.o: badexception.cpp 
	g++ -c badexception.cpp -o badexception.o

group.o: group.cpp group.hpp user.o 
	g++ -c group.cpp -o group.o

element.o: element.cpp element.hpp 
	g++ -c element.cpp -o element.o

directory.o: directory.cpp directory.hpp file.o element.o
	g++ -c directory.cpp -o directory.o

file.o: file.cpp file.hpp element.o 
	g++ -c file.cpp -o file.o

clean:
	rm -r *.o
	rm -r *.out