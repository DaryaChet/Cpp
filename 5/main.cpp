#include "BinaryTreeOfInteger.h"


BinaryTreeOfInteger testMoveConstructor(BinaryTreeOfInteger& tree) {
	
	//tree.insert(7, std::vector<int>{});
	BinaryTreeOfInteger tree2(tree); //��� �������� ����������� �����������
	return tree2; //� ��� ������������ ����������� (������������ R-VALUE ���������� ������, �����������)
}

BinaryTreeOfInteger testMoveOperator(BinaryTreeOfInteger& tree) {

	//tree.insert(-1000, std::vector<int>{});
	BinaryTreeOfInteger tree2(tree); //��� �������� ����������� �����������
	return tree2; //� ��� ������������ ����������� (������������ R-VALUE ���������� ������, �����������)
}

int main() {


	setlocale(LC_ALL, "ru");

	//������� ������
	BinaryTreeOfInteger tree;
	tree.insert(0, std::vector<int>());     //           0
	tree.insert(1, std::vector<int>{0});    //       1      2
	tree.insert(2, std::vector<int>{1});    //    3    4
	tree.insert(3, std::vector<int>{0,0});
	tree.insert(4, std::vector<int>{0, 1});

	//������� ������
	std::cout << tree << std::endl;

	//��������� ������ ������� ��� �������� ���� (������� ������� ��� ������������ ����� - �� 0 ��� 1)
	try {
		tree.insert(100, std::vector<int>{1, 1, 1, 1});
	}
	catch (std::invalid_argument ex) {
		std::cout << std::endl << ex.what() << std::endl;
	}
	try {
		tree.insert(100, std::vector<int>{-1});
	}
	catch (std::invalid_argument ex) {
		std::cout << std::endl << ex.what() << std::endl;
	}

	//��������� ���������� �������
	tree.insert(-1, std::vector<int>{0, 1});
	std::cout << std::endl << "������ ������� � ����� {0, 1}: " << tree << std::endl;

	//������� ������ ������ � ������� ������������ �����������
	std::cout << std::endl << "������� ������ ������ � ������� ������������ �����������: ";
	BinaryTreeOfInteger tree2(tree);
	std::cout << tree2 << std::endl;

	//��������� ��� ��� ������ ��������� �������, ������ ��� ��� ������ ������� � ������
	tree2.insert(100, std::vector<int>{});
	tree.insert(-100, std::vector<int>{1});
	std::cout << std::endl << "���������, ��� ��� ���������� ���������� ���� �� �����: " << tree << " || " << tree2 << std::endl;

	//��������� ����������� �����������
	std::cout << std::endl << "��������� ����������� ����������(������� � ������ ������� ������ 1000): ";
	BinaryTreeOfInteger tree3(testMoveConstructor(tree));
	tree.insert(1000, std::vector<int>{});
	std::cout << tree << " || " << tree3 << std::endl;

	//��������� �������� ������������	
	std::cout << std::endl << "��������� �������� ������������ 1=2 � (������� ������ � tree3): ";
	tree = tree3;
	tree3.removeAllLeaf();// � ������ �������� �������
	std::cout << tree << " || " << tree3 << std::endl;

	//��������� �������� �����������
	std::cout << std::endl << "��������� �������� ���������� (������� � ������ ������� ������ 0): ";
	tree = testMoveConstructor(tree3);
	tree.insert(1000, std::vector<int>{});
	std::cout << tree << " || " << tree3 << std::endl;

	//���������� ������ ����� � ������
	std::cout << std::endl << tree2 << "   ������: " << tree2.getNumberOfEven();
	//      100
	//    1     2
	//  3   -1
	
	//�������� ��� ������ ������������� �����
	std::cout << std::endl << tree2 << "   ������ �������������?: " << tree2.isContainPositiveOnly();
	std::cout << std::endl << tree << "   ������ �������������?: " << tree.isContainPositiveOnly();
	
	//������� ��������������
	std::cout << std::endl << tree2 << "������� ��������������: " << tree2.getArithmeticalMean();
	tree2.insert(99, std::vector<int>{});
	std::cout << std::endl << tree2 << "������� ��������������: " << tree2.getArithmeticalMean();
	tree2.~BinaryTreeOfInteger();
	std::cout << std::endl << tree2 << "������� ��������������: " << tree2.getArithmeticalMean();
	

	tree.insert(0, std::vector<int>());     //             0
	tree.insert(1, std::vector<int>{0});    //       1          2
	tree.insert(2, std::vector<int>{1});    //    3    4
	tree.insert(3, std::vector<int>{0, 0}); //            5
	tree.insert(4, std::vector<int>{0, 1});
	tree.insert(5, std::vector<int>{0, 1, 1});

	//���� ����A
	std::cout << std::endl << tree << "���� � �������� 5: ";
	std::vector<int> path(tree.find(5));
	for (int i : path) {
		std::cout << i << " ";
	}
	std::cout << std::endl << tree << "���� � �������� 100: ";
	path = tree.find(100);
	for (int i : path) {
		std::cout << i << " ";
	}
	std::cout << std::endl << tree << "���� � �������� 3: ";
	path = tree.find(3);
	for (int i : path) {
		std::cout << i << " ";
	}
	


}