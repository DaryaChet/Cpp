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

	std::cout << "������� ������" << std::endl;
	HashTable<int>::Iterator it(table);
	it.start();
	std::vector<int> evenNum;
	while (it.hasNext()) {
		int elem = it.getValue();
		if (elem % 2 == 0) evenNum.push_back(elem);
		it.next();
	}//������� ������
	for (int i : evenNum) {
		table.eraseItem(getKey(i), i);
	}
	print(table);

}
int main() {

	setlocale(LC_ALL, "ru");
	HashTable<int> hashTable(10);//�������
	
	//��������� �������
	for (int i = 0; i < 10; i++) {
		hashTable.insertItem(getKey(i), i);
	}//���������
	hashTable.insertItem(getKey(14), 14); //������ � ������ 4 ��� ��������
	print(hashTable);//�������

	//��������� ��������
	testErase(hashTable);

	std::cout << "������� ������� � ������� ���" << std::endl;
	int i = 9;
	auto finded = hashTable.findItem(getKey(i), i); //������� �������
	std::cout << finded.getValue() << std::endl;// ������� ��� 

	std::cout << "������ ������" << std::endl;
	hashTable.makeEmpty();//������ ������
	std::cout << "������� �����?" << hashTable.isEmpty() << std::endl;//��������� �������
	print(hashTable);//�������

	//�������� ��������������� ��������
	hashTable.eraseItem(getKey(i), i);//i = 9


	//�������� ��������� � ���������� ������
	hashTable.insertItem(0, 1);
	hashTable.insertItem(0, 2);
	hashTable.insertItem(0, 3);
	print(hashTable);
	hashTable.eraseItem(0, 1);
	print(hashTable);

}