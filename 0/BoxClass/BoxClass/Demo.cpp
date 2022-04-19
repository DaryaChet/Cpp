#include "Demo.h"
#include "BoxClass.h"

int main()

{
    const int SIZE = 3;
    Box box1(1, 1, 1, 1, 1);
    Box box2(2, 2, 2, 2, 1);
    Box box3(3, 3, 3, 3, 1);
    Box arrayBox[SIZE]{ box1, box2, box3 };

    for (int i = 0; i < SIZE; i++) {
        std::cout << arrayBox[i] << std::endl;
    }
    std::cout << "Sum values: " << SumValue(arrayBox, SIZE) << std::endl;

    int SUM = 20;
    std::cout << "Check sum all lenghts, widths, heights <= " << SUM << " " << Check3sum(arrayBox, SIZE, SUM) << std::endl;

    int VALUE = 10;
    std::cout << "Max Weight with value <=" << VALUE <<": "  << findMaxWeight(arrayBox, SIZE, VALUE) << std::endl;

    std::cout << "Box in box? " << checkBoxInBox(arrayBox, SIZE) << std::endl;

    std::cout << "box1 == box2? " << (box1 == box2) << std::endl;
    std::cout << "box1 == box1? " << (box1 == box1) << std::endl;
    std::cout << "box1 == box3? " << (box1 == box3) << std::endl;
}
