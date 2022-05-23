#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H

template <typename T> class AbstractIterator;

template <typename T> class AbstractList {		

public:

	//����������� ����� ������� � ����� ������������ �������� ������ �� �������
	AbstractList<T>() {};
	virtual void add(T& element, AbstractIterator<T>* it) = 0;//�������� ������� � �������, ���������� ����������,
	virtual T& pop(AbstractIterator<T>* it) = 0;//	������� �������, ���������� ����������,
	virtual AbstractIterator<T>& findFirstInput(T elem) = 0;//	����� ������ ��������� �������� � ������, ��������� � �������� �� ��������� �������,
	virtual void clear() = 0;//	������� ������ ������,
	virtual bool isEmpty() = 0;//	�������� �� �������,
	virtual size_t getSize() = 0;//	���������� ��������� � ������,
	virtual AbstractIterator<T>& begin() = 0;//	�������� �������� �� ������ ������� ������.
	virtual ~AbstractList<T>() = default;
};
 
template <typename T> class AbstractIterator {

public:

	//����������� ����� ��������� � �������� :
	AbstractIterator(){};
	virtual void start() = 0;//������ ������,
	virtual T& getElement() = 0;//	�������� ��������� �������,
	virtual void next() = 0;//	�������� �������� �� ��������� �������,
	virtual bool finish() = 0;//	��������, ��� �� ��������������.
	virtual ~AbstractIterator() = default;
};
#endif ABSTRACT_LIST_H

