#include <iostream>
#include "RingBuffer.h"

int main() {
	
	int size = 10;
	RingBuffer<int> buffer(size);
	RingBuffer<int>::Iterator<int> it(buffer);
	for (int i = 0; i < size; i++) {
		buffer.push(i);
	}
	it.start();
	while (!it.finish()) {
		std::cout << it.getValue() << " ";
		it.next();
	}
	std::cout << std::endl;
	buffer.pop();
	buffer.pop();
	buffer.pop();
	buffer.push(100);
	buffer.push(100);
	buffer.push(100);

	it.start();
	while (!it.finish()) {
		std::cout << it.getValue() << " ";
		it.next();
	}
	std::cout << std::endl;


	RingBuffer<std::string> strBuff(4);
	RingBuffer<std::string>::Iterator<std::string> iter(strBuff);
	iter.start();
	while (!iter.finish()) {
		std::cout << iter.getValue() << " ";
		iter.next();
	}
	strBuff.push("Hello");
	//strBuff.push(",");
	strBuff.push("beauty");
	strBuff.push("world");
	strBuff.push("!");

	iter.start();
	while (!iter.finish()) {
		std::cout << iter.getValue() << " ";
		iter.next();
	}
	std::cout << std::endl;
	strBuff.pop();
	iter.start();
	while (!iter.finish()) {
		std::cout << iter.getValue() << " ";
		iter.next();
	}
	std::cout << std::endl;
}