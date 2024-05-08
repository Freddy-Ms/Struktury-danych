#include <iostream>
#include "BinaryQueue.cpp"
#include "ListQueue.cpp"
#include "Tests.cpp"

using namespace std;

int main(){
  // PerformTestsLQ();
   //PerformTestsBQ();
int size[]= {100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000};
   for(int i =0;i<10;i++){
      TestGetLast(size[i]); 
   }
   return 0;
}