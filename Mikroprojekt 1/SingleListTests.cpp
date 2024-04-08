#include<iostream>
#include<fstream>
#include "ArrayListTests.cpp"
#include "SingleList.cpp"
#include <iomanip> 
#pragma once
using namespace std;

void testSingleAddLast(){
    cout << "Testing AddLast() function for SingleList" << endl;
    for (int i = 0; i < 6; i++) {
        SingleList<int>* list = new SingleList<int>;
        list->readFromFile("data.txt", elements[i]);
        cout << "Single List: " << elements[i] << " elements" << endl;

        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 10000; j++) {
            list->addLast(15);
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000 << " nanoseconds" << std::endl;
        delete list;
    }
}

void testSingleAddFirst(){
    cout << "Testing AddFirst() function for SingleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        SingleList<int>* list = new SingleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Single List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 10000; j++)
            list->addFirst(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000 << " nanoseconds" << std::endl;
        delete list;
}}

void testSingleaddAt(){
    cout << "Testing AddAt() function for SingleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        SingleList<int>* list = new SingleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Single List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->addAt(elements[i] / 2,15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void testSingleremoveLast(){
    cout << "Testing removeLast() function for SingleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        SingleList<int>* list = new SingleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Single List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->removeLast();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void testSingleremoveFirst(){
    cout << "Testing removeFirst() function for SingleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        SingleList<int>* list = new SingleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Single List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 10000; j++)
            list->removeFirst();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000 << " nanoseconds" << std::endl;
        delete list;
}}

void testSingleListremoveAt(){
    cout << "Testing removeAt() function for SingleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        SingleList<int>* list = new SingleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Single List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->removeAt(elements[i] / 2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void testSingleListContains(){
    cout << "Testing contains() function for SingleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        SingleList<int>* list = new SingleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Single List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->contains(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void perfromSingleListTests(){
    testSingleAddLast();
    testSingleAddFirst();
    testSingleaddAt();
    testSingleremoveLast();
    testSingleremoveFirst();
    testSingleListremoveAt();
    testSingleListContains();
}


