#ifndef  MY_HASH_TABLE_EXCEPTION
#define MY_HASH_TABLE_EXCEPTION
#include <stdexcept>
class HashTableException: public std::exception {
	const char* message;
public:
	HashTableException(const char* msg) :message(msg) {};
	const char* what() { return message; }

};
#endif //MY_HASH_TABLE_EXCEPTION