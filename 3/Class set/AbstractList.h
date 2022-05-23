#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H

template <typename T> class AbstractIterator;

template <typename T> class AbstractList {		

public:

	//јбстрактный класс Ђ—писокї с чисто виртуальными методами работы со списком
	AbstractList<T>() {};
	virtual void add(T& element, AbstractIterator<T>* it) = 0;//вставить элемент в позицию, отмеченную итератором,
	virtual T& pop(AbstractIterator<T>* it) = 0;//	удалить элемент, отмеченный итератором,
	virtual AbstractIterator<T>& findFirstInput(T elem) = 0;//	найти первое вхождение элемента в список, результат Ц итератор на найденный элемент,
	virtual void clear() = 0;//	сделать список пустым,
	virtual bool isEmpty() = 0;//	проверка на пустоту,
	virtual size_t getSize() = 0;//	количество элементов в списке,
	virtual AbstractIterator<T>& begin() = 0;//	получить итератор на первый элемент списка.
	virtual ~AbstractList<T>() = default;
};
 
template <typename T> class AbstractIterator {

public:

	//јбстрактный класс Ђ»тераторї с методами :
	AbstractIterator(){};
	virtual void start() = 0;//начать работу,
	virtual T& getElement() = 0;//	получить очередной элемент,
	virtual void next() = 0;//	сдвинуть итератор на следующий элемент,
	virtual bool finish() = 0;//	проверка, все ли проитерировано.
	virtual ~AbstractIterator() = default;
};
#endif ABSTRACT_LIST_H

