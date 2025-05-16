#include <utility>
#include "heap.h"

MinHeap::MinHeap(int capacity) {
    // 3 arrays needed: storing keys, position, and managing heap.
    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        position[i] = -1;
    }
    this->capacity = capacity; // max size
    size = 0; // delcare size
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

void MinHeap::insert(int vertex, int key) {
    if (size == capacity){
        return;
    }
    size++;
    int i = size - 1;
    heapArray[i] = vertex;
    keyArray[i] = key;
    position[vertex] = i;
    while (i != 0 && keyArray[i] < keyArray[(i - 1) / 2]) {
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
}

int MinHeap::extractMin() {
    // remove + return the min node
    if (isEmpty()) return -1; // EDGE CASE, if heap is empty, there is no min to extract.

    int root = heapArray[0];
    int lastNode = heapArray[size - 1];
    heapArray[0] = lastNode;
    position[root] = -1;
    position[lastNode] = 0; // position of last node at index 0
    keyArray[0] = heapArray[size -1];

    size--; // dec size
    minHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[i] = newKey;
    while (i != 0 && keyArray[i] < keyArray[(i - 1) / 2]) {
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
    position[vertex] = i; // update position
}

bool MinHeap::isInMinHeap(int vertex) {
    //  boolena, return true if vertex v is in heap
    return position[vertex] != -1;
}

bool MinHeap::isEmpty() {
    // boolean, return size of 0 for no nodes present.
    return size == 0;
}

int *heapArray; // Heap of vertex indices
int *keyArray; // Corresponding key values
int *position; // Maps vertex to its position in heap
int capacity;
int size;

int parent(int i) { return (i - 1) / 2; } // simplcity's sake
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void MinHeap::minHeapify(int idx) {
    int l = left(idx), r = right(idx), smallest = idx;
    if (l < size && keyArray[l] < keyArray[smallest]) smallest = l; // checks for left being smaller
    if (r < size && keyArray[r] < keyArray[smallest]) smallest = r; //  checks for right being smaller
    if (smallest != idx) {
        // bubbling down smallest node
        std::swap(position[heapArray[idx]], position[heapArray[smallest]]);
        // swap smallest with curr index (positions).
        std::swap(heapArray[idx], heapArray[smallest]);
        std::swap(keyArray[idx], keyArray[smallest]);
        minHeapify(smallest); // recursive call to method to ensure min heap sturcture is maintained.
    }
}
