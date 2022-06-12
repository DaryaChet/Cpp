#include "DynamicArrayOfInteger.h"
#include <iostream>


int main()
{
	//конструкторы
	DynamicArrayOfInteger intArr1;
	//std::cout << "array1 size:" << intArr1.getSize() << " capacity:" << intArr1.capasity() << " / " <<  intArr1 << std::endl;

	//размеры
	intArr1.reserve(10); //выделить +10
	//std::cout << "array1 size:" << intArr1.getSize() << " capacity:" << intArr1.capasity() << " / " << intArr1 << std::endl;

	intArr1.resize(15); //изменить размер с стандартного (10) на 15 
	for (int i = 0; i < 15; i++) {
		intArr1[i] = i + 1;
	}
	//std::cout << "array1 size:" << intArr1.getSize() << " capacity:" << intArr1.capasity() << " / " << intArr1 << std::endl;

	intArr1.resize(3); //уменьшили до 3
	//std::cout << "array1 size:" << intArr1.getSize() << " capacity:" << intArr1.capasity() << " / " << intArr1 << std::endl;

	DynamicArrayOfInteger intArr2(2,2);
	//std::cout << "array2 size:" << intArr2.getSize() << " capacity:" << intArr2.capasity() << " / " << intArr2 << std::endl;

	DynamicArrayOfInteger intArr3(3, 3, 3);
	//std::cout << "array3 size:" << intArr3.getSize() << " capacity:" << intArr3.capasity() << " / " << intArr3 << std::endl;


	//сложение
	DynamicArrayOfInteger intArr4 = intArr1 + intArr2;
	//std::cout << "array4/1+2 size:" << intArr4.getSize() << " capacity:" << intArr4.capasity() << " / " << intArr4 << std::endl;

	//копирование
	DynamicArrayOfInteger copy(intArr3);
	intArr3[0] = 4; 
	//std::cout << "arrayCopy3  size:" << copy.getSize() << " capacity:" << copy.capasity() << " / " << copy << std::endl;

	//сравнения
	//std::cout << "(intArr1 <= intArr4):" << (intArr1 <= intArr4) << std::endl;
	//std::cout << "(intArr1 < intArr4):" << (intArr1 < intArr4) << std::endl;
	//std::cout << "(intArr1 >= intArr4):" << (intArr1 >= intArr4) << std::endl;
	//std::cout << "(intArr4 > intArr1):" << (intArr4 > intArr1) << std::endl;
	//std::cout << "(intArr1 <= intArr1):" << (intArr1 <= intArr1) << std::endl;
	//std::cout << "(intArr1 < intArr3):" << (intArr1 < intArr3) << std::endl;
	//std::cout << "(intArr1 >= intArr3):" << (intArr1 >= intArr3) << std::endl;
	//std::cout << "(intArr1 > intArr3):" << (intArr1 > intArr3) << std::endl << std::endl;
	
	/*try {
		intArr1 == intArr4;
		intArr1 != intArr4;
	}
	catch (std::exception ex) {
		std::cout << ex.what();
	}*/

	/*std::cout << (intArr1 == intArr1) << std::endl;*/

	intArr2.popBack();
	intArr2.popBack();
	/*try {
		intArr2.popBack();
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}*/
	//std::cout << "array2 size:" << intArr2.getSize() << " capacity:" << intArr2.capasity() << " / " << intArr2 << std::endl;
	for (int i = 0; i < 2; i++) {
		intArr2.pushBack(i+1);
	}
	//std::cout << "array2 size:" << intArr2.getSize() << " capacity:" << intArr2.capasity() << " / " << intArr2 << std::endl;
	DynamicArrayOfInteger last(1);
	//std::cout << "last size:" << last.getSize() << " capacity:" << last.capasity() << " / " << last << std::endl;
	last = intArr1 + intArr2;
	//std::cout << "last size:" << last.getSize() << " capacity:" << last.capasity() << " / " << last << std::endl;
}
