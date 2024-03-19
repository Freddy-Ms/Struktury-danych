#include<iostream>
#include"List.hpp"
using namespace std;
bidirectional_list::bidirectional_list() {
    head = NULL;
    tail = NULL;
    size = 0;
}
bidirectional_list::~bidirectional_list() {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void bidirectional_list::addfirst(int n) {
    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
    if (tail == NULL) {
        tail = temp;
    }
    size++;
}
void bidirectional_list::addlast(int n) {
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    temp->prev = tail;
    if (tail != NULL) {
        tail->next = temp;
    }
    tail = temp;
    if (head == NULL) {
        head = temp;
    }
    size++;
}
void bidirectional_list::addatindex(int n, int index) {
    if (index == 0) {
        addfirst(n);
    }
    else if (index == size) {
        addlast(n);
    }
    else {
        Node *temp = new Node;
        temp->data = n;
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        temp->next = current;
        temp->prev = current->prev;
        current->prev->next = temp;
        current->prev = temp;
        size++;
    }
}
void bidirectional_list::print() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void bidirectional_list::removefirst() {
    if (head != NULL) {
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        size--;
    }
    else {
        cout << "List is empty" << endl;
    }
}
void bidirectional_list::removelast() {
    if (tail != NULL) {
        Node *temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        delete temp;
        size--;
    }
    else {
        cout << "List is empty" << endl;
    }
}
void bidirectional_list::removemiddle(int index) {
    if (index == 0) {
        removefirst();
    }
    else if (index == size-1) {
        removelast();
    }
    else {
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
}
void bidirectional_list::checkvalue(int n) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == n) {
            cout << "Value found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Value not found" << endl;
}