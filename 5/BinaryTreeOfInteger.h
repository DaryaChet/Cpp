#ifndef MY_BINARY_TREE_OF_INTEGER
#define MY_BINARY_TREE_OF_INTEGER
#include <iostream>
#include <vector>

class BinaryTreeOfInteger {

private:

	struct Node{

		int data;
		Node* left;
		Node* right;

		Node() {
			data = 0;
			left = nullptr;
			right = nullptr;
		}

		~Node() {
			left = nullptr;
			right = nullptr;
		}
	};


	Node* root;

	Node* copy(Node* rt);
	void removeLeaf(Node*& rt);
	void deleteTree(Node* rt);
	bool isContainPositiveOnly(Node* rt);
	size_t getNumberOfEven(Node* rt);
	double getSumAndCount(Node*, size_t&);
	bool find(Node* rt, std::vector<int>&, int x);

	void printElem(Node* rt, std::ostream& out);
	
	


public:

	BinaryTreeOfInteger(): root(nullptr){};
	BinaryTreeOfInteger(const BinaryTreeOfInteger& other);
	BinaryTreeOfInteger(BinaryTreeOfInteger&& other);
	void operator=(const BinaryTreeOfInteger& other);
	void operator=(BinaryTreeOfInteger&& other);
	~BinaryTreeOfInteger();

	void insert(int x, std::vector<int> path);
	size_t getNumberOfEven();
	bool isContainPositiveOnly();
	void removeAllLeaf();
	double getArithmeticalMean();
	std::vector<int> find(int x);// ���������� ������ ������ ���� ����� ����� � �����, -1 ���� ������ ����� ���

	friend std::ostream& operator<<(std::ostream& out, BinaryTreeOfInteger& tr) {

		tr.printElem(tr.root,out);
		return out;
	};

};



/*����������� ����� ��������� ������ ����� �����.
������:
� ��������� (������������, ����������, ��������� ������������),
� ������� �������� � ������. ����� �������� �� ���� ����� x, ������� ����� ��������, �
������������������ �� 0 � 1, ���������� ���� � ������: 0 � ������� � ������ ������
�������� ����, 1 � � �������. ���� ���� ����� � ��� ������������ ����, �� ����� � ���
���������� �� x. ���� ���� �������� ����� ���� ������ � ������������� �� ������� ����,
�� � ��� ����� ����������� ����� ���� ��� ������� �����. � ��������� ������� � ������.
� �������� ������ (����� ���� ��������� ������ � ����� ����� �������).
2. �������� � ���������� ����� ������:
� ���������� ������ ����� � ������,
� �������� ����, ��� � ������ ������ ������������� ����� (� ������ ������ �������
��������� true),
� �������� � ������ ���� ������� (��� ���� �������� ������ ����� ����, �� �� �������),
� ������� �������������� ���� ����� � ������,
� ����� ��������� �������� x � ������ (���� ����� ����� ������ � ������ ��������� ���,
�� ������ ������ ���������), ��������� � ���� �� ����� � ���������� ���� � ����
������� �� 0 � 1. ������ ����� ������� � ���� ������� ������ std::vector.*/

#endif