#include <iostream>
#include <fstream>
#include "Template.hpp"
#pragma once 
using namespace std;

template <typename T>
class SingeList : public Template<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data, Node* next = nullptr) : data(data), next(next) {};
    };
    Node* head;
    Node* tail;
    size_t length;
public:
    SingeList(){
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    virtual ~SingeList(){
        Node* temp = head;
        while(temp != nullptr){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr; tail = nullptr; length = 0;
    }

    virtual void addLast(T element) override{
        Node* newNode = new Node(element);
        if(!head) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    virtual void addFirst(T element) override{
        Node* newNode = new Node(element, head);
        if(!head){
            tail = newNode;
            head = newNode;
        }
        head = newNode;
        length++;
    }

    virtual void addAt(int index, T element) override{
        if(index < 0 || index > length){
            cout << "Index out of bounds" << endl;
        }
        if(index == 0)
            addFirst(element);
        else if(index == length)
            addLast(element);
        else{
            Node* newNode = new Node(element);
            Node* temp = head;
            for(int i = 0; i < index - 1; i++) 
                temp = temp->next; 
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
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
            length = 0;
        }else{
        Node* temp = head;
        while(temp->next != tail)
            temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        }length--;
    }

    virtual void removeFirst() override{
        if(!head){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    virtual void removeAt(int index) override{
        if(index < 0 || index >= length){
            cout << "Index out of bounds" << endl;
            return;
        }
        if(index == 0)
            removeFirst();
        else if(index == length - 1)
            removeLast();
        else{
            Node* temp = head;
            for(int i = 0; i < index - 1; i++)
                temp = temp->next;
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            length--;
        }
    }

    virtual T& get(int index) override{
        if(index < 0 || index >= length){
            cout << "Index out of bounds" << endl;
            return head->data;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
    }

    virtual int size() override{
        return length;
    }

    virtual bool isEmpty() override{
        return length == 0;
    }

    virtual void print() override{
        Node* temp = head;
        while(temp != nullptr){
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
        while(temp != nullptr){
            if(temp->data == element)
                return true;
            temp = temp->next;
        }
        return false;
    }
};