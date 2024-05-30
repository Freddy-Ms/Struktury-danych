#include "HashMap.hpp"
#pragma once
template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(size_t capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->table = new Entry[capacity];
    for (int i = 0; i < this->capacity; i++) 
        this->table[i].occupied = false;   
}

template <typename Key, typename Value>
HashMap<Key, Value>::~HashMap() {
    delete[] this->table;
}

template <typename Key, typename Value>
size_t HashMap<Key, Value>::hash(Key key) {
    if(is_same<Key, int>::value) {
        key = ((key >> 16) ^ key) * 0x45d9f3b;
        key = ((key >> 16) ^ key) * 0x45d9f3b;
        key = (key >> 16) ^ key;
        return key % this->capacity;
    }
    else {
        std::hash<Key> hashfunc;
        return hashfunc(key) % this->capacity;
    }
}

template <typename Key, typename Value>
void HashMap<Key, Value>::insert(Key key, Value value) {
    this->isFull();
    size_t index = this->hash(key);
    while (this->table[index].occupied) {
        index = (index + 1) % this->capacity;
    }
    this->table[index] = {key, value, true};
    this->size++;
}

template <typename Key, typename Value>
void HashMap<Key, Value>::remove(Key key) {
    size_t index = this->hash(key);
    while (this->table[index].key != key) {
        index = (index + 1) % this->capacity;
    }
    this->table[index].occupied = false;
    this->size--;
}

template <typename Key, typename Value>
Value HashMap<Key, Value>::get(Key key) {
    size_t index = this->hash(key);
    while (this->table[index].key != key) {
        index = (index + 1) % this->capacity;
    }
    return this->table[index].value;
}

template <typename Key, typename Value>
bool HashMap<Key, Value>::search(Key key) {
    size_t index = this->hash(key);
    size_t iterations = 0;
    while (this->table[index].key != key && iterations < this->capacity) {
        index = (index + 1) % this->capacity;
        iterations++;
    }
    if(iterations == this->capacity)
        return false;
    else
        return this->table[index].occupied;
}

template <typename Key, typename Value>
void HashMap<Key, Value>::print() {
    for (int i = 0; i < this->capacity; i++) {
        if (this->table[i].occupied) {
            cout << this->table[i].key << " " << this->table[i].value << endl;
        }
    }
}

template <typename Key, typename Value>
void HashMap<Key, Value>::rehash() {
    Entry* oldTable = this->table;
    this->capacity *= 2;
    this->size = 0;
    this->table = new Entry[this->capacity];
    for (int i = 0; i < this->capacity; i++) 
        this->table[i].occupied = false;
    for (int i = 0; i < this->capacity / 2; i++) {
        if (oldTable[i].occupied) {
            this->insert(oldTable[i].key, oldTable[i].value);
        }
    }
    delete[] oldTable;
}

template <typename Key, typename Value>
void HashMap<Key, Value>::isFull() {
    if (this->size == this->capacity) 
        this->rehash();
}
