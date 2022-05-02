#ifndef RING_BUFFER_EXCEPT
#define RING_BUFFER_EXCEPT
#include <stdexcept>


class RingBufferException: public std::exception{
	const char* message;
public:
	RingBufferException(const char* msg) : message(msg){};
	const char* what() const noexcept{ return message; };
};
#endif 
