#pragma once
#include <iostream>
using namespace std;
template <typename Key, typename Value>
class HashMap {
private:
    struct Entry {
        Key key;
        Value value;
        bool occupied;
    };
    Entry* table;
    size_t capacity;
    size_t size;
    size_t hash(Key key);    
    void rehash();
    void isFull();
public:
    HashMap(size_t capacity);
    ~HashMap();
    void insert(Key key, Value value);
    void remove(Key key);
    Value get(Key key);
    bool search(Key key);
    void print();

};