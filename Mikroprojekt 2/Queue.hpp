#include <iostream>
#pragma once
using namespace std;

template <typename T>
class Queue {
public:
    virtual ~Queue(){};
    // Adding element with specific priority
    virtual void Add(T element, int priority) = 0;
    // Removing element with the highest priority
    virtual T GetHighest() = 0;
    // Getting size of our queue
    virtual void GetSize() = 0;
    // Peeking what is first in our queue
    virtual void Peek() = 0;
    // Modyfing all elemnts with specific data to another priority
    virtual void Modify(T element, int newPriority) = 0;
    // Reading data from file in each line there should we this pattern : DATA  PRIORITY
    virtual void ReadFile(string, int size) = 0;
    // Printing our data
    virtual void PrintData() = 0;
    // Printing our priorities   ->  checking function
    virtual void PrintPriority() = 0;
};