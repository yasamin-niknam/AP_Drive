#include <iostream>
#include "interface.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	Interface interface = Interface(argv[1]);
	string line;
	while(getline(cin, line))
	{
		interface.process(line);
	}
	return 0;
}