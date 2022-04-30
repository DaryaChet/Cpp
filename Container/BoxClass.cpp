#include "BoxClass.h"


void containers::Box::setLenght(int lenght) {
    if (lenght >= 0) this->length = lenght;
    else throw new std::invalid_argument("Invalid argument");
}
void containers::Box::setWidth(int width) {
    if (width >= 0) this->width = width;
    else throw new std::invalid_argument("Invalid argument");
}
void containers::Box::setHeight(int height) {
    if (height >= 0) this->height = height;
    else throw new std::invalid_argument("Invalid argument"); }
void containers::Box::setValue(int value) {
    if (value >= 0) this->value = value;
    else throw new std::invalid_argument("Invalid argument");
}
void containers::Box::setWeight(double weight) {
    if (weight >= 0) this->weight = weight;
    else throw new std::invalid_argument("Invalid argument");
}

bool containers::Check3sum(containers::Box arrayBox[], int num, int check) {
    /*Напишите функцию, которая проверяет, что сумма длины, ширины и высоты всех коробок
не превосходит заданного значения.*/
    int sum = 0;
    if (arrayBox == nullptr || num < 0) throw std::invalid_argument("invalid arg");
    for (int i = 0; i < num; i++) {
        sum = sum + arrayBox[i].getHeight() + arrayBox[i].getLenght() + arrayBox[i].getWidth();
    }
    return sum <= check;
}

int containers::SumValue(containers::Box arrayBox[], int num) {
    /*Напишите функцию, которая для массива коробок вычисляет суммарную стоимость
 содержимого всех коробок.*/
    int sum = 0;
    if (arrayBox == nullptr || num < 0) throw std::invalid_argument("invalid argument");
    for (int i = 0; i < num; i++) {
        sum = sum + arrayBox[i].getValue();
    }
    return sum;
}

double containers::findMaxWeight(containers::Box arrayBox[], int num, double maxV) {
    /*Напишите функцию, которая определяет максимальный вес коробок, объем которых не
больше параметра maxV.*/
    double maxWeight = 0;

    if (arrayBox == nullptr || num < 0) throw std::invalid_argument("invalid argument");
    for (int i = 0; i < num; i++) {
        int volume = arrayBox[i].getHeight() * arrayBox[i].getLenght() * arrayBox[i].getWidth();
        if (volume >= maxV) {
            maxWeight = arrayBox[i].getWeight();
        }
    }
    return maxWeight;
}

bool containers::checkBoxInBox(containers::Box arrayBox[], const int num) {

    /*В предположении, что все коробки пустые, напишите функцию, которая проверяет, что все
коробки массива можно вложить друг в друга по одной штуке (т.е. самая маленькая
коробка должна содержаться в коробке побольше, эта свою очередь — в еще большей
и т.д.). Считаем, что одна коробка может содержать другую, если длина, ширина и высота
первой коробки больше аналогичных размеров второй.*/

    if (arrayBox == nullptr || num < 0) throw std::invalid_argument("invalid argument");

    containers::Box temp;

    bool result = true;

    for (int i = 1; i < num; i++) {
       
        for (int j = num - 1; j >= i; j--) {

            if (arrayBox[j - 1].getLenght() > arrayBox[j].getLenght() &&
                arrayBox[j - 1].getWidth() > arrayBox[j].getWidth() &&
                arrayBox[j - 1].getHeight() > arrayBox[j].getHeight()) {

                temp = arrayBox[j];
                arrayBox[j] = arrayBox[j - 1];
                arrayBox[j - 1] = temp;

            } else if(arrayBox[j - 1].getLenght() <= arrayBox[j].getLenght() ||
                arrayBox[j - 1].getWidth() <= arrayBox[j].getWidth() ||
                arrayBox[j - 1].getHeight() <= arrayBox[j].getHeight()) {

                result = false;
                break;
            }
        }
    }

    return result;
}

