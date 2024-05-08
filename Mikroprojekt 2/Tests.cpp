#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#pragma once
#include "ListQueue.cpp"
#include "BinaryQueue.cpp"
using namespace std;

int elements[]= {100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000};

void generateData(){
    srand(time(nullptr));
    ofstream file("data.txt");
    int randomNumber, randomPriority;
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return;
    }
    for (int i = 0; i < 1000000; ++i) {
        randomNumber = rand() % 1000000;
        randomPriority = rand() % 1000000 + 1;
        file << randomNumber << " " << randomPriority <<  std::endl;
    }
    file.close();
}

void PerformTestsLQ(){
    for(int i =0;i<10;i++){
        ListQueue<int>* list = new ListQueue<int>();
        auto start = std::chrono::high_resolution_clock::now();
        list->ReadFile("data.txt",elements[i]);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        cout<< "Average time taken by function (ReadFile): " << elapsed.count() << " nanoseconds" << endl;
        start = std::chrono::high_resolution_clock::now();
        list->Add(15,1);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(AddHighest): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        list->GetHighest();
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(GetHighest): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        list->Add(15,1000005);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(AddLowest): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        list->GetLast();
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(GetLowest): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        list->GetSize();
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(GetSize): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        list->Peek();
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(Peek): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        list->ModifyFirst(6391,500);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(ModifyFirst): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        list->Modify(6391,500);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(Modify): " << elapsed.count()  << " nanoseconds" << std::endl;

        delete list;
    }
}

void PerformTestsBQ(){
    for(int i =0 ; i<10;i++){
        BinaryHeap<int>* binary = new BinaryHeap<int>(elements[i]);
        auto start = std::chrono::high_resolution_clock::now();
        binary->ReadFile("data.txt",elements[i]);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> elapsed = end - start;
        cout<< "Average time taken by function (ReadFile): " << elapsed.count() << " nanoseconds" << endl;
        start = std::chrono::high_resolution_clock::now();
        binary->Add(15,1);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(AddHighest): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        binary->GetHighest();
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(GetHighest): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        binary->GetSize();
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(GetSize): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        binary->Peek();
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(Peek): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        binary->ModifyFirst(6391,500);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(ModifyFirst): " << elapsed.count()  << " nanoseconds" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        binary->Modify(6391,500);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Average time taken by function(Modify): " << elapsed.count()  << " nanoseconds" << std::endl;

        delete binary;
    }
}