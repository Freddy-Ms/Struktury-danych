#include <iostream>
#include <fstream>
#include "Template.hpp"
using namespace std;


template <typename T>
class ArrayList : public Template<T> {
    private:
    T* arr;
    int capacity;   // maximum number of elements the list can hold
    int length; // number of elements in the list
    bool isFull(){
        return length == capacity;
    }
    void resize(){
        T* temp = new T[capacity*2];
        for(int i = 0; i < length; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity *= 2;
        }
    public:
    ArrayList(){
        capacity = 10;
        arr = new T[capacity];
        length = 0;
    }
    ArrayList(int capacity){
        this->capacity = capacity;
        arr = new T[capacity];
        length = 0;
    }
    ~ArrayList(){
        delete[] arr;
    }
    
    virtual void addLast(T element) override{
    if(isFull()) resize();
    arr[length] = element;
    length++;
    }
    
    virtual void addFirst(T element) override{
        if(isFull()) resize();
        for(int i = length; i > 0; i--)
            arr[i] = arr[i-1];
        arr[0] = element;
        length++;
    }
    
    virtual void addAt(int index, T element) override{
        if(index < 0 || index > length){
            cout << "Index out of bounds" << endl;
            return;
        }
        if(isFull()) resize();
        for(int i = length ; i >= index; i--){         
            arr[i] = arr[i-1];
        }
        arr[index] = element;
        length++;
    }

    virtual void removeAt(int index) override{
        if(index < 0 || index >= length){
            cout << "Index out of bounds" << endl;
            return;
        }
        for(int i = index; i < length; i++){
            arr[i] = arr[i+1];
        }
        length--;
    }

    virtual void removeLast() override{
        removeAt(length-1);
    }

    virtual void removeFirst() override{
        removeAt(0);
    }

    virtual T& get(int index) override{
        if(index < 0 || index >= length){
            cout << "Index out of bounds" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[index];
    }

    virtual int size() override{
        return length;
    }

    virtual bool isEmpty() override{
        return length == 0;
    }

    virtual void print() override{
        for(int i = 0; i < length; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    virtual void readFromFile(string filename) override{
        ifstream file;
        file.open(filename);
        if(!file){
            cout << "File not found" << endl;
            return;
        }
        T element;
        while(file >> element){
            addLast(element);
        }
        file.close();
    }

    virtual bool contains(const T& element) override{
        for(int i = 0; i < length; i++){
            if(arr[i] == element){
                return true;
            }
        }
        return false;
    }


};