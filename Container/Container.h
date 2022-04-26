#ifndef MY_CLASS_CONTAINER
#define MY_CLASS_CONTAINER
#include <iostream>
#include "BoxClass.h"
#include <vector>
#include <stdexcept>
#include "MyException.h"

namespace containers {
	class Container {
		/*Ќапишите класс Container.  онтейнер содержит коробки (используйте стандартный класс
	vector), он имеет длину, ширину и высоту, а также ограничение на максимальный вес
	своего содержимого. ƒобавьте конструктор по размерам и максимальному весу (создает
	пустой контейнер).*/
	private:

		std::vector<Box> container;
		int length;
		int width;
		int height;
		double MAX_WEIGHT;

	public:

		Container(int lenght, int width, int height, int MAX_SIZE) {
			if (lenght < 0 || width < 0 || height < 0 || MAX_SIZE < 0) throw new std::invalid_argument("invalid argument in Container constructor");
			this->length = lenght;
			this->width = width;
			this->height = height;
			this->MAX_WEIGHT = MAX_SIZE;
		}

		int getNumber() { return container.size(); }
		double getWeight();
		int getValue();
		Box& getBox(int index);

		void add(Box box);
		void remove(int index);

		friend std::ostream& operator <<(std::ostream& os, containers::Container container) {

			os << container.length << "/" << container.width << "/" << container.height << "/" << container.MAX_WEIGHT;
			return os;
		}

		friend std::istream& operator >>(std::istream& is, containers::Container container) {
			
			int length, width, height = 0;
			double MAX_WEIGHT = 0;

			try {
				is >> length >> width >> height >> MAX_WEIGHT;
			}
			catch (std::exception& ex) {
				std::cout << ex.what();
			}

			if (height < 0 || length < 0 || MAX_WEIGHT < 0 || width < 0) throw new std::invalid_argument("incorrect input");
			else {

				container.length = length;
				container.width = width;
				container.height = height;
				container.MAX_WEIGHT = MAX_WEIGHT;

			}
			
			return is;
		}

		Box& operator[](int index);
	};
}
#endif MY_CLASS_CONTAINER