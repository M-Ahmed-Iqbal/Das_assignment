#include"Min_Heap.h"
MinHeap::MinHeap(int maxCapacity) {
    capacity = maxCapacity;
    heapData = new int[capacity];
    size = 0;
}

MinHeap::~MinHeap()
{
    if (heapData == nullptr)
        return;
    delete[] heapData;
    heapData = nullptr;
}

void MinHeap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void MinHeap::insert_iteration(int value) {
    if (size >= capacity) {
        cout << "Heap is full, cannot insert." << endl;
        return;
    }

    size++;
    int index = size - 1;
    heapData[index] = value;

    int currentIndex = index;
    while (currentIndex >= 0 && heapData[getParentIndex(currentIndex)] > heapData[currentIndex]) {
        swap(heapData[getParentIndex(currentIndex)], heapData[currentIndex]);
        currentIndex = getParentIndex(currentIndex);
    }
}
void MinHeap::insert_recursion(int value) {
    if (size >= capacity) {
        cout << "Heap is full, cannot insert." << endl;
        return;
    }

    size++;
    int index = size - 1;
    heapData[index] = value;

    heapify(index);
}

void MinHeap::heapify(int index) {
    if (index > 0 && heapData[index] < heapData[getParentIndex(index)]) {
        swap(heapData[index], heapData[getParentIndex(index)]);
        heapify(getParentIndex(index));
    }
}

int MinHeap::getParentIndex(int index) {
    return (index - 1) / 2;
}

void MinHeap::display()
{

        if (size == 0) {
            cout << "Heap is empty." << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << heapData[i] << " ";
        }
        cout << endl;
    
}
