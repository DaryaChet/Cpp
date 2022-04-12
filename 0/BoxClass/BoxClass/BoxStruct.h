#ifndef MY_BOX_STRUCT
#define MY_BOX_STRUCT
#include <iostream>
#include <stdexcept>

struct Box {

    int lenght;
    int width;
    int height;
    double weight;
    int value;

    Box() : lenght(0), width(0), height(0), weight(0), value(0) {};

    Box(int lenght, int width, int height, double weight, int value) {
        if (lenght > 0 && width > 0 && height > 0 && weight > 0) {
            this->height = height;
            this->lenght = lenght;
            this->width = width;
            this->weight = weight;
            this->value = value;
        }
        else throw std::invalid_argument("invalid argument");
    }

    bool operator == (Box box) {
        return this->height == box.height &&
            this->lenght == box.lenght &&
            this->width == box.width &&
            this->weight == box.weight &&
            this->value == box.value;
    }
};


std::ostream& operator <<(std::ostream& os, const Box box);
std::istream& operator >>(std::istream& is, const Box box);
bool Check3sum(Box arrayBox[], int num, int check);
int SumValue(Box arrayBox[], int num);
double findMaxWeight(Box arrayBox[], int num, double maxV);
bool checkBoxInBox(Box arrayBox[], const int num);

#endif