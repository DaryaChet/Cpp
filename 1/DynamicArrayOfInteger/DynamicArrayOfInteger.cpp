#include "DynamicArrayOfInteger.h"

DynamicArrayOfInteger::DynamicArrayOfInteger(size_t n, int value, size_t reserv) {

	array = new int[n+reserv]{0};
	size = n;
	reserved = reserv;
	for (size_t i = 0; i < n; i++) { array[i] = value; }

}

DynamicArrayOfInteger::DynamicArrayOfInteger(const DynamicArrayOfInteger& other): size(other.size), reserved(other.reserved) {
	
	array = new int[size + reserved]{ 0 };
	for (size_t i = 0; i < size; i++) { array[i] = other.array[i];}
}

DynamicArrayOfInteger::DynamicArrayOfInteger(DynamicArrayOfInteger&& other):size(other.size),array(other.array), reserved(other.reserved) {

	other.array = nullptr;
	other.size = 0;
	other.reserved = 0;
	
};

DynamicArrayOfInteger::~DynamicArrayOfInteger() {

	delete[] array;
	array = nullptr;
}

int& DynamicArrayOfInteger::operator[](const size_t index) {

	if (index >= size) throw new std::invalid_argument("element does not exist");
	else return array[index];

}

int DynamicArrayOfInteger::operator[](const size_t index) const{

	if (index >= size) throw new std::invalid_argument("element does not exist");
	else return array[index];

}

void DynamicArrayOfInteger::resize(const size_t newSize) {
	
	if (size >= newSize) {

		reserved = reserved + (size - newSize);
		size = newSize;
	}
	else if (size + reserved >= newSize) {

		reserved = reserved - (newSize - size);
		size = newSize;
	}
	else {

		int* newArray = new int[newSize]{0};
		for (size_t i = 0; i < size; i++) {
			newArray[i] = array[i];
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
	else throw new std::exception("Array is overflow");
};

int DynamicArrayOfInteger::popBack() {

	if (size != 0) {
		reserved++;
		size--;
		return array[size];
	}
	else throw new std::exception("Array is empty");
};

void DynamicArrayOfInteger::reserve(const size_t reserv) {

	int* newArray = new int[size + reserv]{ 0 };
	reserved = reserved + reserv;
	for (size_t i = 0; i < size; i++) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
}

DynamicArrayOfInteger& DynamicArrayOfInteger::operator=(const DynamicArrayOfInteger& other) {
	
	if (this == &other) return *this;
	if (array) {
		delete[] array;
	}
	size = other.size;
	array = new int[size]{0};
	reserved = other.reserved;
	for (size_t i = 0; i < size; i++) {
		array[i] = other.array[i];
	}
	return *this;
}

DynamicArrayOfInteger& DynamicArrayOfInteger::operator=(DynamicArrayOfInteger&& other) {

	if (this == &other) return *this;
	if (array) {
		delete[] array;
	}
	size = other.size;
	array = other.array;
	reserved = other.reserved;
	other.array = nullptr;
	other.size = 0;
	other.reserved = 0;

	return *this;
}

bool operator==(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {

	if (&first == &second) return true;
	
	if (first.getSize() != second.getSize()) throw new std::exception("Arrays has differents lengths");

	for (size_t i = 0; i < first.getSize(); i++) {

		if (first[i] != second[i]) {return false;}
	}
	return true;

};

bool operator!=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second){

	if (&first != &second) return true;

	if (first.getSize() != second.getSize()) throw new std::exception("Arrays has differents lengths");

	for (size_t i = 0; i < first.getSize(); i++) {

		if (first[i] == second[i]) { return false; }
	}
	return true;

};

bool operator<(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {
	
	if (&first == &second) return false;

	size_t minLenght = std::min(first.getSize(), second.getSize());

	for (size_t i = 0; i < minLenght; i++) {

		if (first[i] < second[i]) { return true; }
		else if (first[i] > second[i]) { return false; }
		else if (i+1 == minLenght) { return (first.getSize()<second.getSize()); }
	}
}

bool operator<=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {

	if (&first == &second) return true;

	size_t minLenght = std::min(first.getSize(), second.getSize());

	for (size_t i = 0; i < minLenght; i++) {

		if (first[i] < second[i]) { return true; }
		else if (first[i] > second[i]) { return false; }
		else if (i + 1 == minLenght) { return (first.getSize() <= second.getSize());}
	}

}
bool operator>(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) { return second < first; };
bool operator>=(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) { return second <= first; };

DynamicArrayOfInteger operator+(const DynamicArrayOfInteger& first, const DynamicArrayOfInteger& second) {

	DynamicArrayOfInteger result(first.getSize() + second.getSize());
	for (size_t i = 0; i < first.getSize(); i++) {
		result[i] = first[i];
	}
	size_t j = 0;
	for (size_t i = first.getSize(); i < first.getSize() + second.getSize(); i++) {
		result[i] = second[j];
		j++;
	}
	return result;

}

std::ostream& operator<<(std::ostream& out, DynamicArrayOfInteger& arr) {
	
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
		throw& ex;
	}
	
	if (arr.array) delete[] arr.array;
	int num = 0;
	for (size_t i = 0; i < tempSize;i++) {

		try {
			in >> num;
		}
		catch (std::exception& ex) {
			throw& ex;
		}

	
	}
	
	return in;

}