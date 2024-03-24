#include<iostream>
using namespace std;
#include "sList.hpp"

sList::sList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}
sList::~sList()
{
    while (head != NULL) {
        sNode *temp = head;
        head = head->next;
        delete temp;
    }
}
void sList::addfirst(int n)
{
    sNode *temp = new sNode;
    temp->data = n;
    temp->next = head;
    head = temp;
    if (tail == NULL) {
        tail = temp;
    }
    size++;
}
void sList::addlast(int n)
{
    sNode *temp = new sNode;
    temp->data = n;
    temp->next = NULL;
    if (tail != NULL) {
        tail->next = temp;
    }
    tail = temp;
    if (head == NULL) {
        head = temp;
    }
    size++;
}
void sList::addatindex(int n, int index)
{
    if(index < 0 || index > size)
    {
        cout << "Invalid index" << endl;
        return;
    }
    if (index == 0) {
        addfirst(n);
    }
    else if (index == size) {
        addlast(n);
    }
    else {
        sNode *prev = nullptr;
        sNode *temp = new sNode;
        temp->data = n;
        sNode *current = head;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = temp;
        temp->next = current;
        size++;
    }
}
void sList::print()
{
    sNode *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void sList::removefirst()
{
    if (head == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        sNode *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}
void sList::removelast()
{
    if (head == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        sNode *current = head;
        sNode *prev = nullptr;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            head = NULL;
            tail = NULL;
        }
        else {
            prev->next = NULL;
            tail = prev;
        }
        delete current;
        size--;
    }
}
void sList::removemiddle(int index)
{
    if (index < 0 || index > size) {
        cout << "Invalid index" << endl;
    }
    else if (index == 0) {
        removefirst();
    }
    else if (index == size) {
        removelast();
    }
    else {
        sNode *current = head;
        sNode *prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
        size--;
    }
}
void sList::checkvalue(int n)
{
    sNode *current = head;
    int index = 0;
    while (current != NULL) {
        if (current->data == n) {
            cout << "Value found at index " << index << endl;
            return;
        }
        current = current->next;
        index++;
    }
    cout << "Value not found" << endl;
}