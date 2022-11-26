#include "BinaryTreeOfInteger.h"
//#define debug

void BinaryTreeOfInteger::deleteTree(Node* rt) {
	
	if (!rt) return;

	deleteTree(rt->left);
	deleteTree(rt->right);
	delete rt;
}

BinaryTreeOfInteger::~BinaryTreeOfInteger() {
	deleteTree(root);
	root = nullptr;
};


BinaryTreeOfInteger::Node* BinaryTreeOfInteger::copy(Node* rt) {

	if (!rt) return nullptr;

	Node* leaf = new Node;
	leaf->data = rt->data;
	leaf->left = copy(rt->left);
	leaf->right = copy(rt->right);
	return leaf;
}

BinaryTreeOfInteger::BinaryTreeOfInteger(const BinaryTreeOfInteger& other) { 
	root = copy(other.root);
	#ifdef debug 
	std::cout << std::endl << "///İÒÎ ÊÎÍÑÒĞÓÊÒÎĞ ÊÎÏÈĞÎÂÀÍÈß///";
	#endif debug
};
BinaryTreeOfInteger::BinaryTreeOfInteger(BinaryTreeOfInteger&& other) : root(other.root) { 
	other.root = nullptr; 
	#ifdef debug 
	std::cout << std::endl << "///İÒÎ ÊÎÍÑÒĞÓÊÒÎĞ ÏÅĞÅÌÅÙÅÍÈß///";
	#endif debug
};

void BinaryTreeOfInteger::operator=(const BinaryTreeOfInteger& other) {

	if (root) deleteTree(root);
	root = copy(other.root);
	#ifdef debug 
	std::cout << std::endl << "///İÒÎ ÎÏÅĞÀÒÎĞ ÏĞÈÑÂÀÈÂÀÍÈß///";
	#endif debug
	
};
void BinaryTreeOfInteger::operator=(BinaryTreeOfInteger&& other) {
	
	if (root) deleteTree(root);
	root = other.root;
	other.root = nullptr;
	#ifdef debug 
	std::cout << std::endl << "///İÒÎ ÎÏÅĞÀÒÎĞ ÏÅĞÅÌÅÙÅÍÈß///";
	#endif debug
};


void BinaryTreeOfInteger::insert(int x, std::vector<int> path) {

	Node* p = root;
	Node* prev = root;

	if (path.empty()) {

		if (root == nullptr) {
			root = new Node;
		}
		root->data = x;
		return;
	}

	for (int i : path) {

		if (!p) throw std::invalid_argument("Wrong way");

		//if(prev == nullptr ) throw std::invalid_argument("Wrong way, it was too long");
		prev = p;

		if (i == 0) p = p->left;
		else if (i == 1) p = p->right;
		else throw std::invalid_argument("Wrong way, the number wasn't 0 or 1");

	}

	if (path.back() == 0) {
		
		if (prev->left == nullptr) prev->left = new Node;
		prev->left->data = x;
	}
	else {

		if (prev->right == nullptr) prev->right = new Node;
		prev->right->data = x;
	}


	
};

void BinaryTreeOfInteger::printElem(Node* rt, std::ostream& out) {

	if (!rt) return;

	out << rt->data << " ";
	printElem(rt->left, out);
	printElem(rt->right, out);

}

size_t BinaryTreeOfInteger::getNumberOfEven(Node* rt) {
	
	if (!rt) return 0;

	return (rt->data%2 == 0) + getNumberOfEven(rt->left) + getNumberOfEven(rt->right);

};


size_t BinaryTreeOfInteger::getNumberOfEven() {

	return getNumberOfEven(root);
};

bool BinaryTreeOfInteger::isContainPositiveOnly(Node* rt) {

	if (!rt) return true;
	
	return (rt->data) > 0 && isContainPositiveOnly(rt->left) && isContainPositiveOnly(rt->right);
};

bool BinaryTreeOfInteger::isContainPositiveOnly() {

	return isContainPositiveOnly(root);
};

void BinaryTreeOfInteger::removeLeaf(Node*& rt) {

	if (!rt) return;
	
	if (rt->left == nullptr && rt->right == nullptr) {
		delete rt;
		rt = nullptr;
		return;
	}

	removeLeaf(rt->left);
	removeLeaf(rt->right);

}
void BinaryTreeOfInteger::removeAllLeaf() {

	this->removeLeaf(root);

};

double BinaryTreeOfInteger::getSumAndCount(Node* rt, size_t& counter) {

	if (!rt) return 0;
	counter++;
	return (rt->data + getSumAndCount(rt->left,counter) + getSumAndCount(rt->right, counter));
};

double BinaryTreeOfInteger::getArithmeticalMean() {

	if (!root) return 0;

	size_t counter = 0; 
	double sum = getSumAndCount(root, counter);
	return sum / counter;
};

bool BinaryTreeOfInteger::find(Node* rt, std::vector<int>& vector,int x) {
	
	if (!rt) {
		return false;
	};

	if (rt->data == x) {
		return true;
	}
	
	if (find(rt->left, vector, x)) {
		vector.push_back(0);
		return true;
	}
	if (find(rt->right, vector, x)) {
		vector.push_back(1);
		return true;
	}

	return false;
};

std::vector<int> BinaryTreeOfInteger::find(int x) {
	//âîçâğàùàåò ïóòü. åñëè ÷èñëî ëåæèò â êîğíå, òî âåêòîğ ïóñòîé. åñëè ÷èñëà íåò, âîçâğàùàåò -1

	std::vector<int> tempVector;
	std::vector<int> result;

	if (!find(root, tempVector, x)) result.push_back(-1);
	else {

		for (int i = tempVector.size() - 1; i >= 0; i--) {
			result.push_back(tempVector[i]);
		}
	}

	return result;
	
};