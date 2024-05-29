#include <iostream>
#pragma once
using namespace std;

template <typename Key, typename Value>
class Cuckoo {
private:
    typedef pair<Key, Value> Pair;
    int one_table_capacity; // Storing capacity of the one hash table
    int capacity; // Storing capacity of the one hash table, so we have to mulitply by 2 to get the total capacity
    int size; // Storing the number of elements in the hash tables
    Pair* table1; // Storing the first hash table
    Pair* table2; // Storing the second hash table
    bool* occupied1; // Storing the status of the first hash table
    bool* occupied2; // Storing the status of the second hash table
    bool isFull(); // Check if the hash tables are full
    int hash1(Key key); // Hash function for the first hash table
    int hash2(Key key); // Hash function for the second hash table
    void rehash(); // Rehash the hash tables
public:
    Cuckoo(int capacity); // Constructor
    ~Cuckoo(); // Destructor
    void insert(Key key, Value value); // Insert a key into the hash tables
    void remove(Key key); // Remove a key from the hash tables
    bool search(Key key); // Search a key in the hash tables


    void display(); // Display the hash tables
};