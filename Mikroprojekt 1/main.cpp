#include<iostream>
#include "ArrayList.cpp"
#include "HeadList.cpp"
#include "SingleList.cpp"
#include "DoubleList.cpp"
using namespace std;

int main(){
    cout << "Hehe" << endl;
    HeadList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);
    list.addLast(6);
    list.addLast(7);
    list.addLast(8);
    list.addLast(9);
    list.addLast(10);
    list.print();
}