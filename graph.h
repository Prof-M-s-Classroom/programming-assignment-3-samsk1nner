#ifndef GRAPH_H
#define GRAPH_H

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
    ~Graph();
    void addEdge(int u, int v, int weight);
    void primMST();  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif