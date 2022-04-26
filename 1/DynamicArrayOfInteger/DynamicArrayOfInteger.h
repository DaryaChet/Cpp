#ifndef MY_DYNAMIC_ARRAY
#define MY_DYNAMIC_ARRAY
#include <stdexcept>
#include <cmath>
#include <iostream>

class DynamicArrayOfInteger
{

private:

	int* array;
	size_t size;
	size_t reserved;

public:
	
	DynamicArrayOfInteger(size_t n = 10, int value = 0, size_t reserev = 0);
	DynamicArrayOfInteger(const DynamicArrayOfInteger& other);
	DynamicArrayOfInteger(DynamicArrayOfInteger&& other);
	~DynamicArrayOfInteger();

	size_t getSize() const { return size; }
	int& operator[](const size_t index);
	int& operator[](const size_t index)const;
	void resize(const size_t newSize);
	void reserve(const size_t reserv);
	void pushBack(const int value);
	int popBack();
	size_t capasity() { return reserved; };
	DynamicArrayOfInteger& operator=(const DynamicArrayOfInteger& other);
	DynamicArrayOfInteger& operator=(DynamicArrayOfInteger&& other);

};

bool operator==(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second);
bool operator!=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second);
bool operator<(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second);
bool operator<=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second);
bool operator>(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second);
bool operator>=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second);
DynamicArrayOfInteger& operator+(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second);
std::ostream& operator<<(std::ostream& out, DynamicArrayOfInteger& arr);
std::istream& operator>>(std::istream& out, DynamicArrayOfInteger& arr);
#endif

