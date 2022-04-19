#ifndef MY_EXCEPTION_FOR_CONTAINER
#define MY_EXCEPTION_FOR_CONTAINER
#include <exception>

class MyException :public std::exception {
private:
public:
	MyException(const char* msg):exception(msg){};
};
#endif