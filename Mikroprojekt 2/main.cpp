#include <iostream>
#include "BinaryQueue.cpp"
#include "ListQueue.cpp"

using namespace std;

int main(){
    ListQueue<int> list;
    list.add(1, 1);
    list.add(2, 2);
    list.add(3, 3);
    list.add(4, 4);
    list.add(5, 5);
    list.add(6, 6);
    list.add(7, 7);
    list.add(8, 8);
    list.add(9, 9);
    list.add(10, 10);
    list.add(0,1);
    list.add(4,1);
    list.printData();
    list.printPriority();
   // list.Modify(5, 1);
   // list.Modify(1, 10);
    list.Modify(4, 100);
    list.printData();
    list.printPriority();
   
}