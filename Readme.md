[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Sam Skinner

## Description      // TODO
At a high level, Prim's Algorithm is used to compute a minimum spanning tree of a weighted graph through a 3 step process.
First, weights of the edges are stored in an adjacency matrix, or a 2D array in the graph.cpp class. The edges in main.cpp are used
to populate the adjacency matrix. From there, a MinHeap is created in heap.cpp/heap.h, where 3 arrays are created: heapArray[], position[], and keyArray[]. 
These arrays, combined with methods consisting of insert, extractMin, and decreaseKey, allow us sort the weights of the vertices to create a min heap. 
Lastly, Prim's Algorithm ties everything together. The vertices are inserted into the heap, where, while the heap isn't empty,
we remove the key for the vertex with the smallest edge. That vertex is included in the MST. From there, we scan the adjacency matrix
to see if there is an edge that is not already in the MST. If that's the case, the key is set to the weight at that vertex, the parent becomes
the previous vertex, and the key is decreased to this new vertex. Once the heap is depleted and the minimum spanning tree has been filled, we print the total cost of the minimum spanning tree and the corresponding adjacency matrix.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE using main.cpp.

## Time Complexity Analysis         // DONE

| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O (log (V))     |
| Extract Min          | O (log (V))     |
| Decrease Key         | O (log (V))     |
| Prim’s MST Overall   | O (v^2)         |

_Explain why your MST implementation has the above runtime._
1. Insertion in MinHeap
   2. This is an O(log(V)) runtime because when inserting a new vertex at the bottom, the process of bubbling up travels -- at most -- the height of the tree.
3. ExtractMin
   4. This is an O(log(V)) runtime because the root is removed O(1), it is replaced with the last element O(1), then going down the heap is O(log(v)). 
5. Decrease Key
   6. This updates the given key O(1), then bubbles that key up the heap O(log(V)).
7. Prim's MST Overall
   8. There are multiple steps here. With the initial inserts of the vertices into the heap (v * log(v)), we then call extract min O(log(v)) to get the smallest value in the heap. From there, for each vertex, the row of the adjacency-matrix is scanned O(v^2). Decrease key is then triggered, but only a runtime of O(log(v)), so the total runtime comes out to be O(v^2). 

## Assumptions
A few assumptions that I made were that the graph is always connected and undirected so that there aren't parallel edges. 
In Q5 of the FAQ, we can assume that the graphs are connected and undirected. In addition, we can assume that we not only need the
adjacency matrix, but also the total edge weights in the final output.

## Test Case Description and Edge Cases       // DONE
1. The first edge case: a graph with 1 vertex
Input: 1 vertex, Output: 0 Edges for cost = 0.
2. Star Graph: no central vertex.
Input: 5 Vertices. Output: 0-1: "5" --> 0-2: "3" --> 0-3: "4" --> 0-4: "1". Total cost = 14

## Challenges
I was banging my head against a wall with a SigSegv error: "(Process finished with exit code 139 (interrupted by signal 11:SIGSEGV))".
This is because I was not initializing the parent vertex, so the parent at index i was indefinitely set to -1, causing the SigSegv error.
To overcome this challenge, I updated the extractMin class to include "keyArray[0] =keyArray[size]" as it was missing before. 
this allowed the keyArray to be synced up with heapArray.