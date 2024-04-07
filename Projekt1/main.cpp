#include <iostream>
#include<chrono>
#include"DynamicT.cpp"
#include"List.cpp"
#include"sList.cpp"
using namespace std;

int main()
{
    sList s;
    for(int i=0;i<10;i++)
    {
        s.addlast(i);
    }
    sList tab[100];
    for(int i=0;i<100;i++)
    {
        tab[i] = s;
    }

    tab[10].print();
    tab[10].addfirst(69);
    tab[10].print();
    cout << endl;
    s.print();
    cout << endl;
    tab[99].print();
    auto start = chrono::high_resolution_clock::now();
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken by sList: " << duration.count() << " nanoseconds" << endl;

}
