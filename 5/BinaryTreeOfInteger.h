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
	std::vector<int> find(int x);// возвращает пустой вектор если число лежит в корне, -1 если такого числа нет

	friend std::ostream& operator<<(std::ostream& out, BinaryTreeOfInteger& tr) {

		tr.printElem(tr.root,out);
		return out;
	};

};



/*–еализовать класс Ђƒвоичное дерево целых чиселї.
ћетоды:
Ц служебные (конструкторы, деструктор, операторы присваивани€),
Ц вставка элемента в дерево. ћетод получает на вход число x, которое нужно вставить, и
последовательность из 0 и 1, кодирующую путь в дереве: 0 Ц переход к левому потоку
текущего узла, 1 Ц к правому. ≈сли путь ведет в уже существующий узел, то число в нем
замен€етс€ на x. ≈сли путь проходит через лист дерева и заканчиваетс€ на уровень ниже,
то в это место добавл€етс€ новый узел как потомок листа. ¬ остальных случа€х Ч ошибка.
Ц оператор вывода (вывод всех элементов дерева в поток слева направо).
2. ƒобавьте в написанный класс методы:
Ц количество четных чисел в дереве,
Ц проверка того, что в дереве только положительные числа (в пустом дереве считаем
результат true),
Ц удаление в дереве всех листьев (при этом листь€ми станут новые узлы, их не трогаем),
Ц среднее арифметическое всех чисел в дереве,
Ц поиск заданного элемента x в дереве (если такое число входит в дерево несколько раз,
то одного любого вхождени€), результат Ч путь от корн€ к найденному узлу в виде
массива из 0 и 1. ћассив можно хранить в виде объекта класса std::vector.*/

#endif