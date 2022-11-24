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
	HashTable<int> hashTable(10);//�������
	
	//��������� �������
	for (int i = 0; i < 10; i++) {
		hashTable.insertItem(i,i);
	}//���������
	hashTable.insertItem(4, 14); //������ � ������ 4 ��� ��������
	print(hashTable);//�������

	//��������� ��������
	std::cout << "������� ������" << std::endl;
	for (int i = 0; i < 10; i++) {
		if (i%2 == 0) hashTable.eraseItem(i, i);
	}//������� ������
	print(hashTable);

	std::cout << "������� ������� � ������� ���" << std::endl;
	int i = 9;
	auto finded = hashTable.findItem(i, i); //������� �������
	std::cout << finded.getValue() << std::endl;// ������� ��� 

	std::cout << "������ ������" << std::endl;
	hashTable.makeEmpty();//������ ������
	std::cout << "������� �����?" << hashTable.isEmpty() << std::endl;//��������� �������
	print(hashTable);//�������


	//�������� ��������������� ��������
	hashTable.eraseItem(i, i);//i = 9


	//�������� ��������� � ���������� ������
	i = 0;
	hashTable.insertItem(i, 1);
	hashTable.insertItem(i, 2);
	hashTable.insertItem(i, 3);
	print(hashTable);
	hashTable.eraseItem(i, 1);
	print(hashTable);

}