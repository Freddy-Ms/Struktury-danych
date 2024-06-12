#include "Graph.cpp"
#include <chrono>
#pragma once 

const int density[] = {25,50,75,100};
const int vertices[] = {10,50,100,500,1000};
void TestsDijkstra()
{
    std::chrono::high_resolution_clock::time_point StartList, EndList,StartMatrix, EndMatrix;
    std::chrono::microseconds ElapsedList, ElapsedMatrix;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<5;j++){
            ElapsedList = std::chrono::microseconds::zero();
            ElapsedMatrix = std::chrono::microseconds::zero();
            for(int k = 0; k<100;k++){
                Graph *g = new Graph(vertices[j]);
                g->generateGraph(density[i]);
                StartList = std::chrono::high_resolution_clock::now();
                g->DijkstraWithList(0);
                EndList = std::chrono::high_resolution_clock::now();
                ElapsedList += std::chrono::duration_cast<std::chrono::microseconds>(EndList - StartList);
                StartMatrix = std::chrono::high_resolution_clock::now();
                g->DijkstraWithMatrix(0);
                EndMatrix = std::chrono::high_resolution_clock::now();
                ElapsedMatrix += std::chrono::duration_cast<std::chrono::microseconds>(EndMatrix - StartMatrix);
                delete g;
            }
            cout << "Average time taken by function(DijkstraWithList) with density " << density[i] << " and vertices " << vertices[j] << " : " << ElapsedList.count()/100 << " microseconds" << endl;
            cout << "Average time taken by function(DijkstraWithMatrix) with density " << density[i] << " and vertices " << vertices[j] << " : " << ElapsedMatrix.count()/100 << " microseconds" << endl;
        }
        
    }
}
void GraphTest()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.DijkstraWithList(0);
    g.DijkstraWithMatrix(0);
}
void TestBellmanFord()
{
    Graph *g = new Graph(6);
    g->addEdgeDirectional(0, 1, 5);
    g->addEdgeDirectional(1, 2, 1);
    g->addEdgeDirectional(1, 3, 2);
    g->addEdgeDirectional(2, 4, 1);
    g->addEdgeDirectional(3, 5, 3);
    g->addEdgeDirectional(4, 3, -1);
    g->addEdgeDirectional(5, 4, -1);
    g->FordBellmanList(0);
    g->FordBellmanMatrix(0);
    delete g;
}
void TestsBellmanFord()
{
    std::chrono::high_resolution_clock::time_point StartList, EndList,StartMatrix, EndMatrix;
    std::chrono::microseconds ElapsedList, ElapsedMatrix;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<5;j++){
            ElapsedList = std::chrono::microseconds::zero();
            ElapsedMatrix = std::chrono::microseconds::zero();
            for(int k = 0; k<1;k++){
                Graph *g = new Graph(vertices[j]);
                g->generateGraphDirectional(density[i]);
                StartList = std::chrono::high_resolution_clock::now();
                g->FordBellmanList(0);
                EndList = std::chrono::high_resolution_clock::now();
                ElapsedList += std::chrono::duration_cast<std::chrono::microseconds>(EndList - StartList);
                StartMatrix = std::chrono::high_resolution_clock::now();
                g->FordBellmanMatrix(0);
                EndMatrix = std::chrono::high_resolution_clock::now();
                ElapsedMatrix += std::chrono::duration_cast<std::chrono::microseconds>(EndMatrix - StartMatrix);
                delete g;
            }
            cout << "Average time taken by function(FordBellmanList) with density " << density[i] << " and vertices " << vertices[j] << " : " << ElapsedList.count()/1 << " microseconds" << endl;
            cout << "Average time taken by function(FordBellmanMatrix) with density " << density[i] << " and vertices " << vertices[j] << " : " << ElapsedMatrix.count()/1 << " microseconds" << endl;
        }
        
    }
}