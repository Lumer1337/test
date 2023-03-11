#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include "Stack.h"

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.saveToFile("myStack.bin");
    myStack.loadFromFile("myStack.bin");

    std::cout << "Stack after saving to file(321): " << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;

    myStack.push(4);
    myStack.push(5);
    myStack.push(6);

    myStack.saveToFile("myStack.bin");
    myStack.loadFromFile("myStack.bin");

    std::cout << "Stack after loading from file(654): " << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;


    std::cout << "Stack after loading from file(-1-1-1): " << std::endl;
    myStack.saveToFile("myStack.bin");
    myStack.loadFromFile("myStack.bin");
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;

    return 0;
}