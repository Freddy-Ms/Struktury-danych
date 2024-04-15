#include<iostream>
using namespace std;

template <typename T>
class Queue {
    public:
    virtual ~Queue(){};
    // Adding element with specific priority
    virtual void add(T element, int priority) = 0;
    // Removing element with the highest priority
    virtual T& getHighest() = 0;
    // Removing element with given index, then repairing the structure
    virtual T& get(int index) = 0;
    // Getting size of our queue
    virtual void getSize() = 0;
    // Peeking what is first in our queue
    virtual void peek() = 0;
    // Modyfing all elemnts with specific data to another priority
    virtual void Modify(T element, int newPriority) = 0;
    // Checking if we have anything in our queue
    virtual bool isEmpty() = 0;
    // Reading data from file in each line there should we this pattern : DATA  PRIORITY
    virtual void ReadFile(string) = 0;
    // Printing our data
    virtual void printData() = 0;
    // Printing our priorities   ->  checking function
    virtual void printPriority() = 0;


};