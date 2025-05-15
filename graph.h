#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;
#include "heap.h"

class Graph {
public:
    Graph(int vertices){
        numVertices = vertices;
        adjMatrix = new int*[vertices];
        for(int i = 0; i < vertices; i++){
            adjMatrix[i] = new int[vertices];
            for(int j = 0; j < vertices; j++){
                adjMatrix[i][j] = 0; // all verticies intialized with 0 edges.
            }
        }
    }
    ~Graph(){
        for(int i = 0; i < numVertices; i++){ 
            delete[] adjMatrix[i]; // delete each row of the adj matrix.
        }
        delete[] adjMatrix; // fully deconstuct adj matrix.
    }

    void addEdge(int u, int v, int weight){
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void primMST(){  
        int* parent = new int[numVertices]; 
        int* key = new int[numVertices];   
        bool* inMST = new bool[numVertices]; 

        for (int i = 0; i < numVertices; i++) {
            key[i] = INT_MAX;
            inMST[i] = false; 
            parent[i] = -1;
        }

        MinHeap heap(numVertices); // heap creation
        key[0] = 0; 
        for (int v = 0; v < numVertices; v++) heap.insert(v, key[v]); // insert veritices into heap

        while (!heap.isEmpty()) {
            int u = heap.extractMin(); 
            inMST[u] = true; 

            for (int v = 0; v < numVertices; v++) { 
                int weight = adjMatrix[u][v]; // edge weight
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) { // edge exists, edge not in MST, edge weight < key at index v
                    parent[v] = u;
                    key[v] = adjMatrix[u][v]; 
                    heap.decreaseKey(v, weight); 
                }
            }
        }

        int totalCost = 0; // print edge weight of the MST
        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (int v = 1; v < numVertices; v++) {
            cout << parent[v] << " - " << v << " : " << adjMatrix[parent[v]][v] << endl;
            totalCost += adjMatrix[parent[v]][v];
        }
        cout << "Total cost of MST: " << totalCost << endl;
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif