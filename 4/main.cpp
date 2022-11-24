#include "HashTable.h"
#include <iostream>

void print(HashTable<int>& table) {
	
	HashTable<int>::Iterator it(table);
	it.start();

	while (it.hasNext()) {
		
		std::cout << it.getValue() << " ";
		it.next();
	
	}
	std::cout << std::endl;
}
int main() {

	setlocale(LC_ALL, "ru");
	HashTable<int> hashTable(10);//создаем
	
	//проверяем вставку
	for (int i = 0; i < 10; i++) {
		hashTable.insertItem(i,i);
	}//заполняем
	hashTable.insertItem(4, 14); //теперь с ключем 4 два элемента
	print(hashTable);//выводим

	//проверяем удаление
	std::cout << "Удаляем четные" << std::endl;
	for (int i = 0; i < 10; i++) {
		if (i%2 == 0) hashTable.eraseItem(i, i);
	}//удаляем четные
	print(hashTable);

	std::cout << "Находим элемент и выводим его" << std::endl;
	int i = 9;
	auto finded = hashTable.findItem(i, i); //находим элемент
	std::cout << finded.getValue() << std::endl;// выводим его 

	std::cout << "Делаем пустым" << std::endl;
	hashTable.makeEmpty();//делаем пустым
	std::cout << "Таблица пуста?" << hashTable.isEmpty() << std::endl;//проверяем пустоту
	print(hashTable);//выводим


	//удаление несуществующего элемента
	hashTable.eraseItem(i, i);//i = 9


	//удаление элементов с одинаковым ключом
	i = 0;
	hashTable.insertItem(i, 1);
	hashTable.insertItem(i, 2);
	hashTable.insertItem(i, 3);
	print(hashTable);
	hashTable.eraseItem(i, 1);
	print(hashTable);

}