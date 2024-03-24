#include<iostream>
using namespace std;

struct sNode
{
    int data;
    sNode* next;
};
class sList
{
    private:
    sNode* head;
    sNode* tail;
    int size;
    public:
    sList();
    ~sList();	
    void addfirst(int);
    void addlast(int);
    void addatindex(int,int);
    void removefirst();
    void removelast();
    void removemiddle(int);
    void checkvalue(int);
    void print();
};