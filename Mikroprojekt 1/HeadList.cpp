#include <iostream>
#include <fstream>
#include "Template.hpp"
#pragma once 
using namespace std;

template <typename T>
class HeadList : public Template<T> {
    private:
        struct Node {
            T data;
            Node* next;
            Node(T data, Node* next = nullptr) : data(data), next(next) {};
        };
        Node* head;
        size_t length;
        Node* tailonlytoloaddata;
    public:
    HeadList(){
        head = nullptr;
        length = 0;
    }
    virtual ~HeadList(){
        Node* temp = head;
        while(temp != nullptr){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr; length = 0;
    }	
    
    virtual void addLast(T element) override{
        Node* newNode = new Node(element);
        if(!head) head = newNode;
        else{
            Node* temp = head;
            while(temp->next)
                temp = temp->next;
            temp->next = newNode;}
        length++;}
  void addLastLoadFromFile(T element) {
        Node* newNode = new Node(element);
        if(!head) {
            head = newNode;
            tailonlytoloaddata = newNode;
        }
        else{
            tailonlytoloaddata->next = newNode;
            tailonlytoloaddata = newNode;
        }
        length++;
    }
    virtual void addFirst(T element) override{
        Node* newNode = new Node(element, head);
        head = newNode;
        length++;}

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
        length++;}}
    
    virtual void removeLast() override{
        if(!head){
            cout << "List is empty" << endl;
            return;
        }
        if(length == 1){
            delete head;
            head = nullptr;
            length = 0;
            return;
        }
        Node* temp = head;
        while(temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        length--;}

    virtual void removeFirst() override{
        if(!head){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;}
    
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
        Node* temp = head;
        for(int i = 0; i < index - 1; i++)
            temp = temp->next;
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        length--;}
    
    virtual T& get(int index) override{
        if(index < 0 || index >= length){
            cout << "Index out of bounds" << endl;
            exit(1);
        }
        Node* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;}

    virtual int size() override{
        return length;}
    
    virtual bool isEmpty() override{
        return length == 0;}

    virtual void print() override{
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;}
        cout << endl;}

    virtual void readFromFile(string filename, int size) override{
        ifstream file;
        file.open(filename);
        if(!file){
            cout << "File not found" << endl;
            return;
        }
        T element;
        int i = 0;
        while(file >> element && i < size){
            addLastLoadFromFile(element);
            i++;
        }
        file.close();
    }
    virtual bool contains(const T& element) override{
        Node* temp = head;
        while(temp){
            if(temp->data == element)
                return true;
            temp = temp->next;}
        return false;}
};