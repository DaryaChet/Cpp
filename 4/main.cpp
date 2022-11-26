#include "HashTable.h"
#include <iostream>
#include <vector>

void print(HashTable<int>& table) {
	
	HashTable<int>::Iterator it(table);
	it.start();

	while (it.hasNext()) {
		
		std::cout << it.getValue() << " ";
		it.next();
	
	}
	std::cout << std::endl;
}

int getKey(int num) {
	return num %10;
}

void testErase(HashTable<int>& table) {

	std::cout << "Удаляем четные" << std::endl;
	HashTable<int>::Iterator it(table);
	it.start();
	std::vector<int> evenNum;
	while (it.hasNext()) {
		int elem = it.getValue();
		if (elem % 2 == 0) evenNum.push_back(elem);
		it.next();
	}//удаляем четные
	for (int i : evenNum) {
		table.eraseItem(getKey(i), i);
	}
	print(table);

}
int main() {

	setlocale(LC_ALL, "ru");
	HashTable<int> hashTable(10);//создаем
	
	//проверяем вставку
	for (int i = 0; i < 10; i++) {
		hashTable.insertItem(getKey(i), i);
	}//заполняем
	hashTable.insertItem(getKey(14), 14); //теперь с ключем 4 два элемента
	print(hashTable);//выводим

	//проверяем удаление
	testErase(hashTable);

	std::cout << "Находим элемент и выводим его" << std::endl;
	int i = 9;
	auto finded = hashTable.findItem(getKey(i), i); //находим элемент
	std::cout << finded.getValue() << std::endl;// выводим его 

	std::cout << "Делаем пустым" << std::endl;
	hashTable.makeEmpty();//делаем пустым
	std::cout << "Таблица пуста?" << hashTable.isEmpty() << std::endl;//проверяем пустоту
	print(hashTable);//выводим

	//удаление несуществующего элемента
	hashTable.eraseItem(getKey(i), i);//i = 9


	//удаление элементов с одинаковым ключом
	hashTable.insertItem(0, 1);
	hashTable.insertItem(0, 2);
	hashTable.insertItem(0, 3);
	print(hashTable);
	hashTable.eraseItem(0, 1);
	print(hashTable);

}