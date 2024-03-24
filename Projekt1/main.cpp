#include <iostream>
#include"DynamicT.cpp"
#include"List.cpp"
#include"sList.cpp"
using namespace std;

int main()
{
    sList s;
    s.addfirst(1);
    s.addfirst(2);
    s.print();
    s.addlast(3);
    s.addlast(4);
    s.print();
    s.addatindex(5, 1);
    s.print();

}
