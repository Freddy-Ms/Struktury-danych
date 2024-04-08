#include<iostream>
#include<fstream>
#include <chrono>

#include<random>
#include "ArrayListTests.cpp"
#include "HeadList.cpp"
#pragma once
using namespace std;

void testHeadAddLast(){
    cout << "Testing AddLast() function for HeadList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        HeadList<int>* list = new HeadList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Head List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->addLast(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " <<   elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void testHeadAddFirst(){
    cout << "Testing AddFirst() function for HeadList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        HeadList<int>* list = new HeadList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Head List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 10000; j++)
            list->addFirst(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000 << " nanoseconds" << std::endl;
        delete list;
}}
void testHeadAddAt(){
    cout << "Testing AddAt() function for HeadList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        HeadList<int>* list = new HeadList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Head List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->addAt(elements[i] / 2,15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}
void testHeadremoveLast(){
    cout << "Testing removeLast() function for HeadList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        HeadList<int>* list = new HeadList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Head List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->removeLast();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}
void testHeadremoveFirst(){
    cout << "Testing removeFirst() function for HeadList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        HeadList<int>* list = new HeadList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Head List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            for(int j = 0; j < 10000; j++)
            list->removeFirst();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count() / 10000 << " nanoseconds" << std::endl;
        delete list;
}}
void testHeadremoveAt(){
    cout << "Testing removeAt() function for HeadList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        HeadList<int>* list = new HeadList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Head List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->removeAt(elements[i] / 2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}
void testHeadContains(){
    cout << "Testing contains() function for HeadList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        HeadList<int>* list = new HeadList<int>; // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Head List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->contains(1000001);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void performHeadTests(){
    testHeadAddLast();
    testHeadAddFirst();
    testHeadAddAt();
    testHeadremoveLast();
    testHeadremoveFirst();
    testHeadremoveAt();
    testHeadContains();
}