//
// Created by Ilya on 11.03.2023.
//
#include <Windows.h>
#include <iostream>
#include "Stack.h"
#include <stdexcept>
using namespace std;


Stack::Stack() {
    size = 10;
    array = new int[size];
    topIndex = -1;
}
Stack::~Stack() {
    delete[] array;
}
void Stack::push(int element) {
    if (topIndex == size - 1) {
        int* newArray = new int[size * 2];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        size *= 2;
    }
    topIndex++;
    array[topIndex] = element;
}
int Stack::pop() {
    if (topIndex == -1) {
        std::cerr << "Stack is empty." << std::endl;
        return -1;
    }
    int element = array[topIndex];
    topIndex--;
    return element;
}
int Stack::peek() {
    if (topIndex == -1) {
        std::cerr << "Stack is empty." << std::endl;
        return -1;
    }
    return array[topIndex];
}
bool Stack::isEmpty() {
    return (topIndex == -1);
}
void Stack::loadFromFile(std::string filename) {
    HANDLE fileHandle = CreateFile(reinterpret_cast<LPCSTR>(L"filename"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
    DWORD bytesRead;
    delete[] array;
    ReadFile(fileHandle, &size, sizeof(int), &bytesRead, NULL);
    array = new int[size];
    ReadFile(fileHandle, &topIndex, sizeof(int), &bytesRead, NULL);
    ReadFile(fileHandle, array, sizeof(int) * (topIndex + 1), &bytesRead, NULL);
    CloseHandle(fileHandle);
}
void Stack::saveToFile(std::string filename) {
    HANDLE fileHandle = CreateFile(reinterpret_cast<LPCSTR>(L"filename"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE) {
        std::cerr << "Error creating file." << std::endl;
        return;
    }
    DWORD bytesWritten;
    WriteFile(fileHandle, &size, sizeof(int), &bytesWritten, NULL);
    WriteFile(fileHandle, &topIndex, sizeof(int), &bytesWritten, NULL);
    WriteFile(fileHandle, array, sizeof(int) * (topIndex + 1), &bytesWritten, NULL);
    CloseHandle(fileHandle);
};
