#include <iostream>
#include"DynamicT.cpp"
using namespace std;

int main()
{
    DynamicT d(10);
    d.addfirst(5);
    d.addfirst(4);
    d.print();
    d.addlast(6);
    d.addlast(7);
    d.print();
    d.addatindex(8,2);
    d.addatindex(9,2);
    d.print();
    d.removemiddle(2);
    d.print();
    d.removelast();
    d.print();
    d.removefirst();
    d.print();
}
