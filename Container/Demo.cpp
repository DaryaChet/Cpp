#include "Demo.h"
#include "MyException.h"

int main()

{
    const int SIZE = 3;
    containers::Box box1(3, 3, 3, 1, 5);
    containers::Box box2(2, 1, 2, 4, 2);
    containers::Box box3(2, 1, 1, 3, 1);
    containers::Box arrayBox[SIZE]{ box1, box2, box3 };

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

    //Container

    containers::Container container(5,5,5,5);
    std::cout << "Container " << container << " was" << " created" << std::endl;
    container.add(box1);
    container.add(box2);
    container.remove(1);
    container.add(box2);
    std::cout << container.getBox(0) << std::endl;
    std::cout << container[1] << std::endl;
    std::cout << "Container value: " << container.getValue() << std::endl;
    std::cout << "Container weight: " << container.getWeight() << std::endl;
    std::cout << container.getNumber() << " box in container";


}
