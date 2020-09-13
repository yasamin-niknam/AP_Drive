#ifndef BADEXCEPTION_CLASS
#define BADEXCEPTION_CLASS

#include <iostream>

class BadException
{
public:
	BadException(std::string _data) : data(_data) {}
	void print();
private:
	std::string data;
};

#endif