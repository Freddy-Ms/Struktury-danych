#include <iostream>
#pragma once
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
    void insert(const Key& key, const Value& value);
    void remove(const Key& key);
    Value get(const Key& key);
    bool search(const Key& key);
    void print();
};