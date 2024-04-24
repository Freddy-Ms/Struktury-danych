#include <iostream>
#include<fstream>
#include "Queue.hpp"

using namespace std;


template <typename T>
class BinaryHeap : public Queue<T>
{
  private:
    struct Node
    {
        T data;
        int priority;
    };
    Node* HeapArr;
    int capacity;
    int actualsize;
    void HeapifyUp(int index)
    {
        int parent = (index - 1) / 2;
        while(index >= 0 && HeapArr[parent].priority > HeapArr[index].priority){
            {
                swap(HeapArr[parent], HeapArr[index]);
                index = parent;
                parent = (index - 1) / 2;
            }
        }
    }
    void HeapifyDown(int index)
    {
        while(1){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if(left < actualsize && HeapArr[left].priority < HeapArr[index].priority)
            smallest = left;
        if(right < actualsize && HeapArr[right].priority < HeapArr[smallest].priority)
            smallest = right;
        if(smallest != index)
        {
            swap(HeapArr[index], HeapArr[smallest]);
            index = smallest;
        }else break;}
    }
    bool isFull() {
        return actualsize == capacity;}
    bool isEmpty() {
        return actualsize == 0;}
    void resize(){
        Node* temp = new Node[capacity * 2];
        for(int i = 0; i < capacity; i++)
            temp[i] = HeapArr[i];
        delete[] HeapArr;
        HeapArr = temp;
        capacity *= 2;
    }
    public:
    BinaryHeap() : BinaryHeap(16){}
    BinaryHeap(int Capacity) : capacity(Capacity), actualsize(0), HeapArr(new Node[Capacity]){}
    ~BinaryHeap(){ delete[] HeapArr; }
    virtual void add(T element, int priority) override{
        if(isFull()) resize();
        HeapArr[actualsize]= {element, priority};
        HeapifyUp(actualsize);
        actualsize++;
    }
    virtual T getHighest() override{
        if(isEmpty()) throw "Queue is empty";
        T temp = HeapArr[0].data;
        HeapArr[0] = HeapArr[actualsize - 1];
        actualsize--;
        HeapifyDown(0);
        return temp;
    }
    virtual void getSize() override{
        cout << "Size of our queue is: " << actualsize << endl;
    }
    virtual void peek() override{
        if(isEmpty()) throw "Queue is empty";
        cout << "First element in our queue is: " << HeapArr[0].data << endl;
    }
    virtual void printData() override{
        for(int i = 0; i < actualsize; i++)
            cout << HeapArr[i].data << " ";
        cout << endl;
    }
    virtual void printPriority() override{
        for(int i = 0; i < actualsize; i++)
            cout << HeapArr[i].priority << " ";
        cout << endl;
    }
    virtual void ReadFile(string filename){
        ifstream file;
        file.open(filename);
        if(!file.is_open()) throw "File not found";
        T data;
        int priority;
        while(file >> data >> priority)
            add(data, priority);
        file.close();
    }
    virtual void Modify(T element, int newPriority) override{
        bool found = false;
        for(int i = 0; i < actualsize; i++){
            if(HeapArr[i].data == element)
            {
                found = true;
                if(newPriority > HeapArr[i].priority)
                {
                    HeapArr[i].priority = newPriority;
                    HeapifyDown(i);
                }else{
                    HeapArr[i].priority = newPriority;
                    HeapifyUp(i);
                }
               
            }
        }
        if(!found)
        cout << "Element not found" << endl;
    }
    void ModifyFirst(T element, int newPriority){
        for(int i = 0; i < actualsize; i++){
            if(HeapArr[i].data == element)
            {
                if(newPriority > HeapArr[i].priority)
                {
                    HeapArr[i].priority = newPriority;
                    HeapifyDown(i);
                }else{
                    HeapArr[i].priority = newPriority;
                    HeapifyUp(i);
                }
                return;
            }
        }
        cout << "Element not found" << endl;
    }
};