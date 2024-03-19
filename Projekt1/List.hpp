#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
class bidirectional_list{
    public:
        bidirectional_list();
        ~bidirectional_list();
        void addfirst(int);
        void addlast(int);
        void addatindex(int,int);
        void removefirst();
        void removelast();
        void removemiddle(int);
        void checkvalue(int);
        void print();
    private:
        Node *head;
        Node *tail;
        int size;
};
