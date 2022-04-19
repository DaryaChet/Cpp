#include "Container.h"

containers::Box& containers::Container::operator[](int index) {
	if (index >= container.size()) throw new MyException("element does not exist");
	return container.at(index);
};


double containers::Container::getWeight() {
	double sum = 0;
	for (Box& box : container) {
		sum += box.getWeight();
	}
	return sum;

}
int containers::Container::getValue() {
	int sum = 0;
	for (Box& box : container) {
		sum += box.getValue();
	}
	return sum;
}

containers::Box& containers::Container::getBox(int index) {
	if (index >= 0 && container.size() > index) return container.at(index);
	else throw new std::invalid_argument("No one box to this index");
}

void containers::Container::add(Box box) {
	if (MAX_WEIGHT - getWeight() < box.getWeight()) {
		throw new MyException("Box was not add");
	}else container.push_back(box);
}

void containers::Container::remove(int index) {
	
	if (index >= 0 && index < container.size()) {
		container.erase(container.begin()+index);
	}
}