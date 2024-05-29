#include "HashTable.hpp"
#include<iostream>

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t size) {
    this->size = size;
    this->table = new list<Pair>*[size];
    for (size_t i = 0; i < size; i++) 
        this->table[i] = new list<Pair>;    
}

template <typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {
    for (size_t i = 0; i < size; i++) 
        delete this->table[i];
    delete[] this->table;
}

template <typename Key, typename Value>
size_t HashTable<Key, Value>::hash(Key key) {
    if(is_same<Key, int>::value) {
        key = ((key >> 16) ^ key) * 0x45d9f3b;
        key = ((key >> 16) ^ key) * 0x45d9f3b;
        key = (key >> 16) ^ key;
        return key % this->size;
    }
    else {
        std::hash<Key> hashfunc;
        return hashfunc(key) % this->size;
    }
}
template <typename Key, typename Value>
void HashTable<Key, Value>::insert(Key key, Value value) {
    if(this->search(key)) {
        cout << "Key already exists" << endl;
        return;
    }
    size_t index = hash(key);
    this->table[index]->emplace_back(key, value);
}
template <typename Key, typename Value>
void HashTable<Key, Value>::remove(Key key) {
    size_t index = hash(key);
    for (auto it = this->table[index]->begin(); it != this->table[index]->end(); it++) {
        if (it->first == key) {
            this->table[index]->erase(it);
            break;
        }
    }
}
template <typename Key, typename Value>
bool HashTable<Key, Value>::search(Key key) {
    size_t index = hash(key);
    for (auto it = this->table[index]->begin(); it != this->table[index]->end(); it++) {
        if (it->first == key) {
            return true;
        }
    }
}
template <typename Key, typename Value>
void HashTable<Key, Value>::display() {
    for (size_t i = 0; i < size; i++) {
        cout << i << ": ";
        for (auto it = this->table[i]->begin(); it != this->table[i]->end(); it++) {
            cout << it->first << " " << it->second <<endl;
        }
        cout << endl;
    }
}
template <typename Key, typename Value>
Value HashTable<Key, Value>::get(Key key) {
    size_t index = hash(key);
    for (auto it = this->table[index]->begin(); it != this->table[index]->end(); it++) {
        if (it->first == key) {
            return it->second;
        }
    }
    return Value();
}