#include <iostream>
#include"DynamicT.cpp"
#include"List.cpp"
using namespace std;

int main()
{
    bidirectional_list l;
    l.addfirst(5);
    l.addfirst(4);
    l.print();
    l.addlast(6);
    l.addlast(7);
    l.print();
    l.addatindex(8,2);
    l.addatindex(9,2);
    l.print();
    l.removemiddle(2);
    l.print();
    l.removelast();
    l.print();
    l.removefirst();
    l.print();

}
