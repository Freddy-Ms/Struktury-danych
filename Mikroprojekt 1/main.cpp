#include<iostream>
#include "ArrayList.cpp"
#include "HeadList.cpp"
#include "SingleList.cpp"
#include "DoubleList.cpp"
#include "ArrayListTests.cpp"
#include"HeadListTests.cpp"
#include "SingleListTests.cpp"
#include"DoubleListTests.cpp"

using namespace std;

int main(){
   // generatedata();
    performArrayTests();
    performHeadTests();
    perfromSingleListTests();
    performDoubleListTests();
}