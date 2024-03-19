#include<iostream>
using namespace std;

class DynamicT {
    public:
        DynamicT(int);
        ~DynamicT();
        void resize();
        void addfirst(int);
        void addlast(int);
        void addatindex(int,int);
        void removefirst();
        void removelast();
        void removemiddle(int);
        void checkvalue(int);
        void print();
    private:
        int *arr;
        int size;
        int capacity;
};