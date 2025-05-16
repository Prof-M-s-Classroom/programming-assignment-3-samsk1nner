#ifndef HEAP_H
#define HEAP_H
#include <utility>

class MinHeap {
public:
    MinHeap(int capacity);
    ~MinHeap();

    void insert(int vertex, int key);
    int extractMin();
    void decreaseKey(int vertex, int newKey);
    bool isInMinHeap(int vertex);
    bool isEmpty();

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx);
};

#endif