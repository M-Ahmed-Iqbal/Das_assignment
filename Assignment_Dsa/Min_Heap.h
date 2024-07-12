#pragma once
#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heapData;
    int capacity;
    int size;

public:
    MinHeap(int maxCapacity);
    ~MinHeap();
    void insert_iteration(int value);
    void insert_recursion(int value);
    void heapify(int index);
    int getParentIndex(int index);
    void display();
    void swap(int& a, int& b);
   
};