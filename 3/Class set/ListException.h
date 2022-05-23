#ifndef LIST_EXCEPTION
#define LIST_EXCEPTION
#include <exception>
class ListException: public std::exception {

	const char* message;
public:
	ListException(const char* msg) :message(msg) {};
	const char* what() { return message; }
};
#endif LIST_EXCEPTION