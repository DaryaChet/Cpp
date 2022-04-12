#include "BoxStruct.h"


std::ostream& operator <<(std::ostream& os, const Box box) {
    os << box.lenght << "/" << box.width << "/" << box.height << " " << box.weight << " " << box.value << " ";
    return os;
}

std::istream& operator >>(std::istream& is, Box box) {
    is >> box.lenght >> box.width >> box.height >> box.weight >> box.value;
    return is;
}

bool Check3sum(Box arrayBox[], int num, int check) {
    /*Напишите функцию, которая проверяет, что сумма длины, ширины и высоты всех коробок
не превосходит заданного значения.*/
    int sum = 0;
    if (arrayBox == nullptr || num < 0) throw std::invalid_argument("invalid arg");
    for (int i = 0; i < num; i++) {
        sum = sum + arrayBox[i].height + arrayBox[i].lenght + arrayBox[i].width;
    }
    return sum <= check;
}

int SumValue(Box arrayBox[], int num) {
   /*Напишите функцию, которая для массива коробок вычисляет суммарную стоимость
содержимого всех коробок.*/
    int sum = 0;
    if (arrayBox == nullptr || num < 0) throw std::invalid_argument("invalid argument");
    for (int i = 0; i < num; i++) {
            sum = sum + arrayBox[i].value;
    }
    return sum;
}

double findMaxWeight(Box arrayBox[], int num, double maxV) {
    /*Напишите функцию, которая определяет максимальный вес коробок, объем которых не
больше параметра maxV.*/
    double maxWeight = 0;

    if (arrayBox == nullptr || num < 0) throw std::invalid_argument("invalid argument");
    for (int i = 0; i < num; i++) {
        int volume = arrayBox[i].height * arrayBox[i].lenght * arrayBox[i].width;
        if (volume >= maxV) {
            maxWeight = arrayBox[i].weight;
        }
    }
    return maxWeight;
}

bool checkBoxInBox(Box arrayBox[], const int num) {

    /*В предположении, что все коробки пустые, напишите функцию, которая проверяет, что все
коробки массива можно вложить друг в друга по одной штуке (т.е. самая маленькая
коробка должна содержаться в коробке побольше, эта свою очередь — в еще большей
и т.д.). Считаем, что одна коробка может содержать другую, если длина, ширина и высота
первой коробки больше аналогичных размеров второй.*/

    if (arrayBox == nullptr || num < 0) throw std::invalid_argument("invalid argument");
    
    Box temp;

    for (int i = 1; i < num; i++) {

        for (int j = num - 1; j >= i; j--) {

            if (arrayBox[j - 1].lenght > arrayBox[j].lenght &&
                arrayBox[j - 1].width > arrayBox[j].width &&
                arrayBox[j - 1].height > arrayBox[j].height) {

                    temp = arrayBox[j];
                    arrayBox[j] = arrayBox[j - 1];
                    arrayBox[j - 1] = temp;
                }
        }
    }

    bool result = true;

    for (int j = 1; j < num; j++){
        if (arrayBox[j - 1].lenght >= arrayBox[j].lenght ||
            arrayBox[j - 1].width >= arrayBox[j].width ||
            arrayBox[j - 1].height >= arrayBox[j].height) {
            result = false;
            break;
        } 
    }

    return result;
}


