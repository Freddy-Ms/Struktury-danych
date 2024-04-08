#include<iostream>
#include<fstream>
#include "ArrayListTests.cpp"
#include "DoubleList.cpp"
#pragma once
using namespace std;

void testDoubleAddLast(){
    cout << "Testing AddLast() function for DoubleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        DoubleList<int>* list = new DoubleList<int>;// Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "DoubleList: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            for(int j = 0; j < 10000; j++)
            list->addLast(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000 << " nanoseconds" << std::endl;
        delete list;
}}

void testDoubleAddFirst(){
    cout << "Testing AddFirst() function for DoubleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        DoubleList<int>* list = new DoubleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Double List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 10000; j++)
            list->addFirst(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000  << " nanoseconds" << std::endl;
        delete list;
}}

void testDoubleaddAt(){
    cout << "Testing AddAt() function for DoubleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        DoubleList<int>* list = new DoubleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Double List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->addAt(elements[i] / 2,15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void testDoubleremoveLast(){
    cout << "Testing removeLast() function for DoubleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        DoubleList<int>* list = new DoubleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Double List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 10000; j++)
            list->removeLast();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000 << " nanoseconds" << std::endl;
        delete list;
}}

void testDoubleremoveFirst(){
    cout << "Testing removeFirst() function for DoubleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        DoubleList<int>* list = new DoubleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Double List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            for(int j = 0; j < 10000; j++)
            list->removeFirst();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000  << " nanoseconds" << std::endl;
        delete list;
}}

void testDoubleremoveAt(){
    cout << "Testing removeAt() function for DoubleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        DoubleList<int>* list = new DoubleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Double List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->removeAt(elements[i] / 2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() << " nanoseconds" << std::endl;
        delete list;
}}

void testDoublecontains(){
    cout << "Testing contains() function for DoubleList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        DoubleList<int>* list = new DoubleList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Double List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->contains(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()   << " nanoseconds" << std::endl;
        delete list;
}}

void performDoubleListTests(){
    testDoubleAddLast();
    testDoubleAddFirst();
    testDoubleaddAt();
    testDoubleremoveLast();
    testDoubleremoveFirst();
    testDoubleremoveAt();
    testDoublecontains();
}