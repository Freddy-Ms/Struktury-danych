#include <iostream>
#pragma once
using namespace std;

template <typename T>
class Template {
    public:
    virtual ~Template(){};
    /*
        Add an element to the end of the list
    */
    virtual void addLast(T element) = 0;
    
    /*
        Add an element to the beginning of the list
    */
    virtual void addFirst(T element) = 0;

    /*
        Add an element at a specific index
    */
   virtual void addAt(int index, T element) = 0;

    /*
        Remove an element from the end of the list
    */
    virtual void removeLast() = 0;

    /*
        Remove an element from the beginning of the list
    */
    virtual void removeFirst() = 0;

    /*
        Remove an element at a specific index
    */
    virtual void removeAt(int index) = 0;

    /*
        Get the element at a specific index
    */
    virtual T& get(int index) = 0;


    /*
        Get the size of the list
    */
    virtual int size() = 0;

    /*
        Check if the list is empty
    */
    virtual bool isEmpty() = 0;

    /*
        Print the list
    */
    virtual void print() = 0;

    /*
        Read data from a file
    */
    virtual void readFromFile(string filename, int size) = 0;

    /*
        Check if the list contains a specific element
    */
    virtual bool contains(const T& element) = 0;



};
