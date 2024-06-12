#include <iostream>
#include <list>
#pragma once
using namespace std;
typedef pair<int, int> vPair; // Vertex Pair to store weight and destination vertex
class Graph {
    private:
        int Vertex; // Number of vertices
        int Edges; // Number of edges
        int **AdjMatrix;    // Adjacency Matrix - Macierz sąsiedztwa
        list<pair<int,int>> *AdjList; // Adjacency List - Lista sąsiedztwa
        void InitializationMatrix(); // Initialize Adjacency Matrix with 0, 0 means there is no edge between two vertices
        void DestroyMatrix(); // Destroy Adjacency Matrix
        void FullfilZerosMatrix(); // Fill Adjacency Matrix with 0
        void ClearAdjList(); // Clear Adjacency List
    public:
        Graph(int Vertex); // Constructor
        void addEdge(int V1, int V2, int weight); // Add edge between two vertices
        void addEdgeDirectional(int V1, int V2, int weight); // Add directional edge between two vertices
        void removeEdge(int V1, int V2); // Remove edge between two vertices
        void DijkstraWithMatrix(int StartVertex); // Dijkstra algorithm with Adjacency Matrix
        void DijkstraWithList(int StartVertex); // Dijkstra algorithm with Adjacency List
        void FordBellmanMatrix(int StartVertex); // Ford-Bellman algorithm
        void FordBellmanList(int StartVertex); // Ford-Bellman algorithm
        void printSolution(int *dist); // Print the solution of Dijkstra or Ford-Bellman algorithm
        void printMatrix(); // Print Adjacency Matrix
        void printList(); // Print Adjacency List
        int getVertex(); // Get number of vertices
        int getEdges(); // Get number of edges
        void generateGraph(int density); // Generate random graph
        void generateGraphDirectional(int density); // Generate random directional graph            
        ~Graph(); // Destructor
};