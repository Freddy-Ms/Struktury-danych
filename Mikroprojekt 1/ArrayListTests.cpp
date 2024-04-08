#include<iostream>
#include<fstream>
#include <chrono>
#include<random>
#include "ArrayList.cpp"
#pragma once
using namespace std;

int elements[] ={100000, 200000, 300000, 400000, 500000, 1000000};


void generatedata(){
    srand(time(nullptr));
    ofstream file("data.txt");
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return;
    }
    for (int i = 0; i < 1000000; ++i) {
        int randomNumber = rand() % 1000000;
        file << randomNumber << std::endl;
    }
    file.close();

}void testArrayAddLast(){
    cout << "Testing AddLast() function for ArrayList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        ArrayList<int>* list = new ArrayList<int>(elements[i]); // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Array List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->addLast(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void testArrayAddFirst(){
    cout << "Testing AddFirst() function for ArrayList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        ArrayList<int>* list = new ArrayList<int>(elements[i]); // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Array List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->addFirst(15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}
void testArrayAddAt(){
    cout << "Testing AddAt() function for ArrayList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        ArrayList<int>* list = new ArrayList<int>(elements[i]); // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Array List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->addAt(elements[i] / 2,15);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void testArrayremoveLast(){
    cout << "Testing RemoveLast() function for ArrayList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        ArrayList<int>* list = new ArrayList<int>(elements[i]); // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Array List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->removeLast();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}

void testArrayremoveFirst(){
    cout << "Testing RemoveFirst() function for ArrayList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        ArrayList<int>* list = new ArrayList<int>(elements[i]); // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Array List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->removeFirst();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
}}
void testArrayremoveAt(){
    cout << "Testing removeAt() function for ArrayList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        ArrayList<int>* list = new ArrayList<int>(elements[i]); // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Array List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->removeAt(elements[i] / 2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
    }}
void testContains()
{
    cout << "Testing contains() function for ArrayList" << endl;
    int value;
    for(int i = 0; i < 6; i++){
        ArrayList<int>* list = new ArrayList<int>(elements[i]); // Declare ArrayList outside the loop
        list->readFromFile("data.txt",elements[i]);
        cout << "Array List: " << elements[i] << " elements" << endl;
        auto start = std::chrono::high_resolution_clock::now();
            list->contains(1000001);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        std::cout << "Average time taken by function: " << elapsed.count()  << " nanoseconds" << std::endl;
        delete list;
    }
}
void performArrayTests(){
    testArrayAddLast();
    testArrayAddFirst();
    testArrayAddAt();
    testArrayremoveLast();
    testArrayremoveFirst();
    testArrayremoveAt();
    testContains();
}