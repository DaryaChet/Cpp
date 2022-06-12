#ifndef MY_HASH_TABLE
#define MY_HASH_TABLE
#include "HashTableException.h"

template <typename T> class HashTable {

private:

	struct Node {

		T data;
		Node* next;

	};

	size_t initialCapacity;
	Node* table;

public:

	class Iterator {

	private:

		Node* table;
		Node* pointer;
		size_t capacityOfHashTable;
		size_t counter;

		friend class HashTable<T>;

	public:

		Iterator(const HashTable<T>& hashTable) : table(hashTable.table), pointer(&hashTable.table[0])
			, capacityOfHashTable(hashTable.initialCapacity), counter(0) {};

		void start() {

			if (capacityOfHashTable == 0) throw HashTableException("Capacity of hash table was bad");

			pointer = table[0].next;

			while (pointer == nullptr && counter < capacityOfHashTable) {
				
				counter++;
				pointer = table[counter].next;
			}
		}

		void next() {
	
			pointer = pointer->next;

			while (pointer == nullptr && counter < capacityOfHashTable) {

				counter++;
				pointer = table[counter].next;

			}
		}

		bool hasNext() {
			return counter < capacityOfHashTable;
		}

		T& getValue() {
			return pointer->data;
		}

		~Iterator() {}

	};

	HashTable(size_t initialCapacity = 10);
	~HashTable();

	size_t hash(int key)const { return key % initialCapacity; };
	void insertItem(int key, T& item);
	void eraseItem(int key, T& item);
	Iterator findItem(int key, T& item) const;//	 найти элемент,
	void makeEmpty();//	 сделать таблицу пустой,
	bool isEmpty() const;//	 проверка таблицы на пустоту.

};

template <typename T> HashTable<T>::HashTable(size_t initialCapacity): initialCapacity(initialCapacity), table(new Node[initialCapacity]) {
	
	for (int i = 0; i < initialCapacity; i++) {
		table[i].next = nullptr;
	}
}

template <typename T> HashTable<T>::~HashTable() {

	if (!isEmpty()) makeEmpty();
	delete[] table;
	table = nullptr;
}

template <typename T> void HashTable<T>::insertItem(int key, T& item) {

	size_t index = hash(key);
	Node* temp = new Node;
	temp->data = item;
	temp->next = table[index].next;
	table[index].next = temp;

}

template <typename T> void HashTable<T>::eraseItem(int key, T& item) {

	size_t index = hash(key);

	Node* temp = table[index].next;
	Node* previousTemp = &table[index];

	if (temp == nullptr) return;

	while (temp->next != nullptr) {

		if (temp->data == item) break;
		previousTemp = temp;
		temp = temp->next;
	}
	
	previousTemp->next = temp->next;
	delete temp;
}

template <typename T> typename HashTable<T>::Iterator HashTable<T>::findItem(int key, T& item) const {

	size_t index = hash(key);
	Node* temp = table[index].next;

	while (temp!= nullptr && temp->data != item) {
		temp = temp->next;
	}

	Iterator it(*this);
	it.counter = index;
	it.pointer = temp;

	return it;
}

template <typename T> void HashTable<T>::makeEmpty(){

	for (int i = 0; i < initialCapacity; i++) {

		while (table[i].next != nullptr) {

			Node* temp = table[i].next->next;
			delete table[i].next;
			table[i].next = temp;

		}
	}
}

template <typename T> bool HashTable<T>::isEmpty() const{

	for (int i = 0; i < initialCapacity; i++) {
	
		if (table[i].next != nullptr) return false;
	
	}

	return true;
}


#endif // !MY_HASH_TABLE



