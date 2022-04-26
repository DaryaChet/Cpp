#ifndef MY_BOX_CLASS
#define MY_BOX_CLASS
#include <iostream>
#include <stdexcept>

namespace containers{

    class Box {


    private:

        int length;
        int width;
        int height;
        double weight;
        int value;

    public:

        Box() : length(0), width(0), height(0), weight(0), value(0) {};

        Box(int lenght, int width, int height, double weight, int value) {
            if (lenght > 0 && width > 0 && height > 0 && weight > 0) {
                this->height = height;
                this->length = lenght;
                this->width = width;
                this->weight = weight;
                this->value = value;
            }
            else throw std::invalid_argument("invalid argument");
        }

        int getLenght() { return length; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        int getValue() { return value; }
        double getWeight() { return weight; }

        void setLenght(int lenght);
        void setWidth(int width);
        void setHeight(int height);
        void setValue(int value);
        void setWeight(double weight);

        bool operator == (Box box) {
            return this->height == box.height &&
                this->length == box.length &&
                this->width == box.width &&
                this->weight == box.weight &&
                this->value == box.value;
        }

        friend std::ostream& operator <<(std::ostream& os, const containers::Box box) {
            os << box.length << "/" << box.width << "/" << box.height << " " << box.weight << " " << box.value << " ";
            return os;
        }

        friend std::istream& operator >>(std::istream& is, containers::Box box) {
            
            int length, width, height, value = 0;
            double weight = 0;

            try {
                is >> length >> width >> height >> weight >> value;
            }
            catch (std::exception & ex) {
                std::cout << ex.what();
             }
            box.setHeight(height);
            box.setLenght(length);
            box.setWidth(width);
            box.setWeight(weight);
            box.setValue(value);
            
            return is;
        }
    };



    bool Check3sum(Box arrayBox[], int num, int check);
    int SumValue(Box arrayBox[], int num);
    double findMaxWeight(Box arrayBox[], int num, double maxV);
    bool checkBoxInBox(Box arrayBox[], const int num);
}
#endif
