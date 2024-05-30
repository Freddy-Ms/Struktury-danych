#include<iostream>
#include<list>
#pragma once 
using namespace std;
template <typename Key, typename Value>
class HashTable{
private:
    typedef pair<Key, Value> Pair;
    size_t size; // Size of the hash table
    list<Pair>** table; // Pointer to an array containing lists of pairs
    size_t hash(Key key); // Hash function
public:
    HashTable(size_t size); // Constructor
    ~HashTable(); // Destructor
    void insert(const Key& key,const Value& value); // Insert a key into the hash table
    void remove(const Key& key); // Remove a key from the hash table
    bool search(const Key& key); // Search a key in the hash table
    void display(); // Display the hash table
    Value get(const Key& key); // Get the value of a key
    size_t get_size() { return this->size; }
    size_t get_size_of_bucket(size_t index) { return this->table[index]->size(); }
};