#pragma once
#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heapData;
    int capacity;
    int size;

public:
    MaxHeap(int maxCapacity);
    ~MaxHeap();
    void insert(int value);
    void increaseKey(int index);
    void removeNode_iteration(int value);
    void removeNode_recursion(int value);
    int findIndex(int value, int index);  //recursive function used in removeNode_recursion
    int getParentIndex(int index);
    int getLeftChildIndex(int index);
    int getRightChildIndex(int index);
    void display();
    void extractMax();
    void heapifyDown(int heapSize, int index);
    void swap(int& a, int& b);
};






