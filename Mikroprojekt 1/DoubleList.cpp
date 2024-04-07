#include <iostream>
#include <fstream>
#include "Template.hpp"
#pragma once 
using namespace std;


template <typename T>
class DoubleList : public Template<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T data, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) {};
    };
    Node* head;
    Node* tail;
    size_t length;
    Node* getNode(int index){
        Node* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
        return temp;
    }
public:
    DoubleList(){
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    virtual ~DoubleList(){
        Node* temp = head;
        while(temp != nullptr){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr; tail = nullptr; length = 0;
    }

    virtual void addLast(T element) override{
        Node* newNode = new Node(element,nullptr,tail);
        if(!head) 
            head = newNode;
        if(tail) tail->next = newNode;
        tail = newNode;
        length++;
    }

    virtual void addFirst(T element) override{
        Node* newNode = new Node(element, head, nullptr);
        if(!tail)
            tail = newNode;     
        if(head)
            head->prev = newNode;
        head = newNode;
        length++;
    }

    virtual void addAt(int index, T element) override{
        if(index < 0 || index > length){
            cout << "Index out of bounds" << endl;
            return;
        }
        Node* existingNode = getNode(index);
        Node* newNode = new Node(element, existingNode, existingNode->prev);
        if(existingNode->prev)
            existingNode->prev->next = newNode;
        if(existingNode)
            existingNode->prev = newNode;
        if(existingNode == head)
            head = newNode;
        if(existingNode == tail)
            tail = newNode;
        length++;
    
    }

    virtual void removeLast() override{
        if(!head){
            cout << "List is empty" << endl;
            return;
        }
        if(length == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length--;
    }

    virtual void removeFirst() override{
        if(!head){
            cout << "List is empty" << endl;
            return;
        }
        Node* toDelete = head;
        head = head->next;
        if(!head) tail = nullptr;
        else head->prev = nullptr;
        delete toDelete;
        }
    
    virtual void removeAt(int index) override{
        if(index < 0 || index >= length){
            cout << "Index out of bounds" << endl;
            return;
        }
        if(index == 0){
            removeFirst();
            return;
        }
        if(index == length - 1){
            removeLast();
            return;
        }
        Node* toDelete = getNode(index);
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        delete toDelete;
        length--;
    }

    virtual T& get(int index) override{
        if(index < 0 || index >= length){
            cout << "Index out of bounds" << endl;
            exit(1);
        }
        return getNode(index)->data;
    }

    virtual int size() override{
        return length;
    }

    virtual bool isEmpty() override{
        return length == 0;
    }
    virtual void print() override{
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    virtual void readFromFile(string filename) override{
        ifstream file(filename);
        if(!file.is_open()){
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
        Node* temp = head;
        while(temp){
            if(temp->data == element)
                return true;
            temp = temp->next;
        }
        return false;
    }


};