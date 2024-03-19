#include<iostream>
#include"DynamicT.hpp"
using namespace std;
DynamicT::DynamicT(int s) {
    size = 0;
    capacity = s;
    arr = new int[capacity];
}
DynamicT::~DynamicT() {
    delete[] arr;
}
void DynamicT::resize() {
    int *temp = new int[capacity*2];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    capacity *= 2;
}
void DynamicT::addfirst(int n) {
    if (size == capacity) {
        resize();
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = n;
    size++;
}
void DynamicT::addlast(int n) {
    if (size == capacity) {
        resize();
    }
    arr[size] = n;
    size++;
}
void DynamicT::addatindex(int n, int index) {
    if (size == capacity) {
        resize();
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = n;
    size++;
}
void DynamicT::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void DynamicT::removefirst() {
    if(size > 0){
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i+1];
    }
    size--;}
    else{
        cout << "Array is empty" << endl;
    }
}
void DynamicT::removelast() {
    if(size > 0){
    size--;
    }
    else{
        cout << "Array is empty" << endl;
    }
}
void DynamicT::removemiddle(int n) {
    if(size>0 && n<size){
    for (int i = n; i < size; i++) {
        arr[i] = arr[i+1];
    }
    size--;}
    else{
        cout << "Array is empty or index is out of range" << endl;
    }
}
void DynamicT::checkvalue(int n) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            cout << "Value found at index " << i << endl;
            return;
        }
    }
    cout << "Value not found" << endl;
}