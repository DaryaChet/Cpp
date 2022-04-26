#include <iostream>
#include "DynamicArrayOfInteger.h"

int main()
{
	//constructors
	DynamicArrayOfInteger intArr1;
	for (size_t i = 0; i < intArr1.getSize(); i++) {
		std::cout << intArr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << intArr1.getSize() << " ";
	std::cout << intArr1.capasity() << " ";
	std::cout << std::endl;


	DynamicArrayOfInteger intArr2(2);
	for (size_t i = 0; i < intArr2.getSize(); i++) {
		std::cout << intArr2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << intArr2.getSize() << " ";
	std::cout << intArr2.capasity() << " ";
	std::cout << std::endl;

	DynamicArrayOfInteger intArr3(3, 3);
	for (size_t i = 0; i < intArr3.getSize(); i++) {
		std::cout << intArr3[i] << " ";
	}
	std::cout << std::endl;
	std::cout << intArr3.getSize() << " ";
	std::cout << intArr3.capasity() << " ";
	std::cout << std::endl;

	DynamicArrayOfInteger intArr4(4, 4, 4);
	for (size_t i = 0; i < intArr4.getSize(); i++) {
		std::cout << intArr4[i] << " ";
	}
	std::cout << std::endl;
	std::cout << intArr4.getSize() << " ";
	std::cout << intArr4.capasity() << " ";
	std::cout << std::endl;

	DynamicArrayOfInteger copy(intArr4);
	intArr4.pushBack(4);
	for (size_t i = 0; i < intArr4.getSize(); i++) {
		std::cout << intArr4[i] << " ";
	}
	std::cout << std::endl;
	std::cout << intArr4.getSize() << " ";
	std::cout << intArr4.capasity() << " ";
	std::cout << std::endl;

	for (size_t i = 0; i < copy.getSize(); i++) {
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;
	std::cout << copy.getSize() << " ";
	std::cout << copy.capasity() << " ";
	std::cout << std::endl;


	//equals
	std::cout << (intArr4 > intArr4) << " " << (intArr4 >= intArr4) << " " << (intArr4 == intArr4) << " " << std::endl;
	std::cout << (intArr1 != intArr2) << " " << (intArr3 != intArr3);
	std::cout << (intArr3 < intArr4) << " " << (intArr3 <= intArr3);

	//capacity

	
}
