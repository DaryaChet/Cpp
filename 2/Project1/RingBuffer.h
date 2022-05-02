#ifndef RING_BUFFER
#define RING_BUFFER
#include "RingBufferException.h"

///class RingBuffer////////////////////////////////////////////////
template<typename T> class RingBuffer {

private:

	//friend class Iterator;
	T* array;
	size_t startIndex;
	size_t arraySize;
	size_t arrayMaxSize;//+1buff elem

public:

	RingBuffer(size_t);
	void push(const T& element);//--добавить элемент в конец очереди(при переполнении Ц исключение),
	T& pop();//	--вз€ть элемент в начале очереди(при отсутствии Ц исключение),
	T& front()const;//	--получить элемент в начале очереди(без его изъ€ти€),
	size_t size()const;//	--размер очереди,
	void clear();//	--сделать очередь пустой,
	bool isEmpty();//	--проверка очереди на пустоту.
	~RingBuffer();

	template <typename T>
	class Iterator {

	private:
		
		friend class RingBuffer;
		T* current;
		RingBuffer<T>* buffer;

	public:

		Iterator(RingBuffer<T>& buff) :buffer(&buff),current(nullptr) {};
		void start() { current = &buffer->array[buffer->startIndex]; }; // начать перебор элементов
		void next() {
			if (current + 1 == buffer->array + buffer->arrayMaxSize) current = buffer->array;
			else current++;

		}; // перейти к следующему элементу
		bool finish() { 
			size_t index = (buffer->startIndex + buffer->arraySize) % buffer->arrayMaxSize;
			return current == &buffer->array[index]; }; // проверка, все ли проитерировано
		T& getValue()const { return *current; }; // получить очередной элемент очереди
		~Iterator() { current = nullptr; }

	};

};
template<typename T> RingBuffer<T>::RingBuffer(size_t n) :startIndex(0), arraySize(0), arrayMaxSize(n+1) { array = new T[arrayMaxSize+1]; }


template<typename T> void RingBuffer<T>::push(const T& element) {

	if (arraySize+1 == arrayMaxSize) throw RingBufferException("Buffer is overflow");

	array[(startIndex + arraySize) % arrayMaxSize] = element;
	arraySize++;



}//--добавить элемент в конец очереди(при переполнении Ц исключение),

template<typename T> T& RingBuffer<T>::pop() {

	if (arraySize == 0) throw RingBufferException("Buffer is empty");

	arraySize--;
	startIndex = (startIndex + 1) % arrayMaxSize;
	return array[startIndex];

}//	--вз€ть элемент в начале очереди(при отсутствии Ц исключение),

template<typename T> T& RingBuffer<T>::front()const {

	if (arraySize == 0) throw RingBufferException("Buffer is empty");
	return &array[startIndex];

}//	--получить элемент в начале очереди(без его изъ€ти€),

template<typename T> size_t RingBuffer<T>::size()const {
	return this->arraySize;
}//	--размер очереди,

template<typename T> void RingBuffer<T>::clear() {
	delete[] array;
	array = nullptr;
}//	--сделать очередь пустой,

template<typename T> bool RingBuffer<T>::isEmpty() {
	return (arraySize == 0);
}//	--проверка очереди на пустоту.

template<typename T> RingBuffer<T>::~RingBuffer() {
	this->clear();
}


#endif RING_BUFFER