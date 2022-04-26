#include "DynamicArrayOfInteger.h"

DynamicArrayOfInteger::DynamicArrayOfInteger(size_t n, int value, size_t reserv) {

	array = new int[n+reserv];
	size = n;
	reserved = reserv;
	for (size_t i = 0; i < n; i++) { array[i] = value; }

}

DynamicArrayOfInteger::DynamicArrayOfInteger(const DynamicArrayOfInteger& other): size(other.size), array(new int[size]) {
	
	for (size_t i = 0; i < size; i++) { this->array[i] = other.array[i];}
}

DynamicArrayOfInteger::DynamicArrayOfInteger(DynamicArrayOfInteger&& other):size(other.size),array(other.array) {

	other.array = nullptr;
	other.size = 0;
	other.reserved = 0;
};

DynamicArrayOfInteger::~DynamicArrayOfInteger() { delete[] array;}

int& DynamicArrayOfInteger::operator[](const size_t index) {

	if (index >= size) throw new std::invalid_argument("element does not exist");
	return array[index];

}

int& DynamicArrayOfInteger::operator[](const size_t index) const{

	if (index >= size) throw new std::invalid_argument("element does not exist");
	return array[index];

}

void DynamicArrayOfInteger::resize(const size_t newSize) {
	
	if (size >= newSize) {

		reserved = reserved + size - newSize;
		size = newSize;
	}
	else if (size + reserved >= newSize) {

		reserved = reserved - (newSize - size);
		size = newSize;
	}
	else {

		int* newArray = new int[newSize] {0};
		for (size_t i = 0; i < std::min(size, newSize); i++) {
			newArray[i] = this->array[i];
		}
		delete[] array;
		array = newArray;
		size = newSize;
		reserved = 0;
	}

}

void DynamicArrayOfInteger::pushBack(const int value) {

	if (reserved != 0) {
		array[size] = value;
		size++;
		reserved--;
	}
	else throw new std::exception("Error of array size");
};

int DynamicArrayOfInteger::popBack() {

	reserved++;
	size--;
	return array[size];
};

void DynamicArrayOfInteger::reserve(const size_t reserv) {

	int* newArray = new int[size+reserv] {0};
	for (size_t i = 0; i < size + reserv; i++) {
		newArray[i] = this->array[i];
	}
	delete[] array;
	array = newArray;
	size = size + reserv;
	reserved = reserv;
}

DynamicArrayOfInteger& DynamicArrayOfInteger::operator=(const DynamicArrayOfInteger& other) {
	
	if (this == &other) return *this;
	if (array) delete[] array;
	size = other.size;
	array = new int[size];
	for (size_t i = 0; i < size; i++) {
		array[i] = other.array[i];
	}
	return *this;
}

DynamicArrayOfInteger& DynamicArrayOfInteger::operator=(DynamicArrayOfInteger&& other) {

	if (this != &other) return *this;

	if (array) delete[] array;

	size = other.size;
	array = other.array;
	other.array = nullptr;
	other.size = 0;

	return *this;
}

bool operator==(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {

	if (&first == &second) return true;
	if (&first == nullptr || &second == nullptr) return false;
	
	if (first.getSize() == second.getSize()) {

		for (size_t i = 0; i < first.getSize(); i++) {

			if (first[i] != second[i]) {return false;}
		}
	}
	else throw new std::exception("Arrays has differents lengths");
};

bool operator!=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second){

	if (&first != &second) return true;

	if (first.getSize() == second.getSize()) {

		for (size_t i = 0; i < first.getSize(); i++) {

			if (first[i] == second[i]) { return false;}
		}
	}
	else throw new std::exception("Arrays has differents lengths");

};

bool operator<(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {
	
	if (first == second) return false;
	if (&first == nullptr || &second == nullptr) return false;

	for (size_t i = 0; i < std::min(first.getSize(), second.getSize()); i++) {
		if (first[i] >= second[i]) return false;
	}
	return true;
}

bool operator<=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {

	if (first == second) return true;
	if (&first == nullptr || &second == nullptr) return false;

	for (size_t i = 0; i < std::min(first.getSize(), second.getSize()); i++) {
		if (first[i] > second[i]) return false;
	}
	return true;
}
bool operator>(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {

	if (first == second) return false;
	if (&first == nullptr || &second == nullptr) return false;

	for (size_t i = 0; i < std::min(first.getSize(), second.getSize()); i++) {
		if (first[i] <= second[i]) return false;
	}
	return true;
}

bool operator>=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {

	if (first == second) return true;
	if (&first == nullptr || &second == nullptr) return false;

	for (size_t i = 0; i < std::min(first.getSize(), second.getSize()); i++) {
		if (first[i] < second[i]) return false;
	}
	return true;
}

DynamicArrayOfInteger& operator+(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {

	DynamicArrayOfInteger result(first.getSize() + second.getSize());
	for (size_t i = 0; i < first.getSize(); i++) {
		result[i] = first[i];
	}
	for (size_t i = first.getSize()-1; i < second.getSize(); i++) {
		result[i] = second[i];
	}
	return result;

}

std::ostream& operator<<(std::ostream& out, DynamicArrayOfInteger& arr) {
	
	out << arr.getSize() << " " << arr.capasity() << std::endl;
	for (size_t i = 0; i < arr.getSize(); i++) {
		out << arr[i] << " ";
	}

	return out;
}
std::istream& operator>>(std::istream& in, DynamicArrayOfInteger& arr) {

	size_t tempSize = 0;
	try {
		in >> tempSize;
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
	
	if()
	
	

}