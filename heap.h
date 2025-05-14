#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity){
        heapArray = new int[capacity + 1];
        keyArray = new int[capacity + 1];
        position = new int[capacity + 1];
        this->capacity = capacity;
        size = 0;
    }
    ~MinHeap(){
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key); // add vertex v with key into the heap.
    // insert at the end of heap array, filter up, then update postion

    int extractMin(); // remove + return the min node

    void decreaseKey(int vertex, int newKey); // set new key for vertex v and update position

    bool isInMinHeap(int vertex){ //  boolena, return true if vertex v is in heap
        return position[vertex] != -1;
    }

    bool isEmpty() {  // boolean, return size of 0 for no nodes present.
        return size == 0; 
    } 

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx);
};

#endif