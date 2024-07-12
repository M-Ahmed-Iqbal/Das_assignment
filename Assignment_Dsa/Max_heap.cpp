#include"Max_heap.h"

MaxHeap::MaxHeap(int maxCapacity) {
    capacity = maxCapacity;
    heapData = new int[capacity];
    size = 0;
}

void MaxHeap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void MaxHeap::insert(int value) {
    if (size >= capacity) {
        cout << "Heap is full, cannot insert." << endl;
        return;
    }

    size++;
    int index = size - 1;
    heapData[index] = value;

    int currentIndex = index;
    while (currentIndex >= 0 && heapData[getParentIndex(currentIndex)] < heapData[currentIndex]) {
        swap(heapData[getParentIndex(currentIndex)], heapData[currentIndex]);
        currentIndex = getParentIndex(currentIndex);
    }
}

int MaxHeap::getParentIndex(int index) {
    return (index - 1) / 2;
}

void MaxHeap::increaseKey(int i) {
    heapData[i] = INT_MAX;
    while (i >= 0 && heapData[getParentIndex(i)] < heapData[i]) {
        swap(heapData[getParentIndex(i)], heapData[i]);
        i = getParentIndex(i);
    }
}

void MaxHeap::removeNode_iteration(int value) {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    
    int index = 0;
    for ( index= 0; index < size; index++) 
    {
        if (heapData[index] == value) {
            break;
        }
    }
    if (index >= size)
    {
        cout << "the value is not present in tree" << endl;;
        return;
    }
    increaseKey(index);
    extractMax();
}
void MaxHeap::removeNode_recursion(int value) {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    int index = findIndex(value, 0);
    if (index == -1) {
        cout << "The value is not present in the tree." << endl;
        return;
    }

    increaseKey(index);
    extractMax();
}
int MaxHeap::findIndex(int value, int index) {
    if (index >= size) {
        return -1; // Value not found
    }

    if (heapData[index] == value) {
        return index; // Value found
    }
    int Index = findIndex(value, ++index); 

    return Index;
}
void MaxHeap::extractMax() {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    size--;
    swap(heapData[0], heapData[size]);
    heapifyDown(size, 0);
}

void MaxHeap::heapifyDown(int heapSize, int index) {
    int largest = index;
    int leftChild = getLeftChildIndex(index);
    int rightChild = getRightChildIndex(index);

    if (leftChild < heapSize && heapData[leftChild] > heapData[largest]) {
        largest = leftChild;
    }
    if (rightChild < heapSize && heapData[rightChild] > heapData[largest]) {
        largest = rightChild;
    }
    if (index != largest) {
        swap(heapData[index], heapData[largest]);
        heapifyDown(heapSize, largest);
    }
}

int MaxHeap::getLeftChildIndex(int index) {
    return 2 * index + 1;
}

int MaxHeap::getRightChildIndex(int index) {
    return 2 * index + 2;
}

void MaxHeap::display() {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << heapData[i] << " ";
    }
    cout <<endl;
}

MaxHeap::~MaxHeap()
{
    if (heapData == nullptr)
        return;
    delete[] heapData;
    heapData = nullptr;
}
