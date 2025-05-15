#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
    Graph(int vertices);
    ~Graph();

    void addEdge(int u, int v, int weight);
    void primMST();

private:
    int** adjMatrix;
    int numVertices;
};

#endif