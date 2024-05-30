#include "Cuckoo.hpp"
#include <type_traits>
#include <string>
#pragma once

template <typename Key, typename Value>
Cuckoo<Key, Value>::Cuckoo(int capacity) {
    this->one_table_capacity = capacity / 2;
    this->capacity = this->one_table_capacity * 2;
    this->size = 0;
    this->table1 = new Pair[one_table_capacity];
    this->table2 = new Pair[one_table_capacity];
    this->occupied1 = new bool[one_table_capacity];
    this->occupied2 = new bool[one_table_capacity];
    for (int i = 0; i < one_table_capacity; i++) {
        this->occupied1[i] = false;
        this->occupied2[i] = false;
    }
}
template <typename Key, typename Value>
Cuckoo<Key, Value>::~Cuckoo() {
    delete[] this->table1;
    delete[] this->table2;
    delete[] this->occupied1;
    delete[] this->occupied2;
}
template <typename Key, typename Value>
bool Cuckoo<Key, Value>::isFull() {
    return this->size == this->capacity;
}
template <typename Key, typename Value>
size_t Cuckoo<Key, Value>::hash1(Key key) {
    if(is_same<Key, int>::value) {
        key = ((key >> 16) ^ key) * 0x45d9f3b;
        key = ((key >> 16) ^ key) * 0x45d9f3b;
        key = (key >> 16) ^ key;
        return key % this->one_table_capacity;
    } else {
        hash<Key> hashfunc;
        return hashfunc(key) % this->one_table_capacity;
    }
}
template <typename Key, typename Value>
size_t Cuckoo<Key, Value>::hash2(Key key) {
    if(is_same<Key, int>::value) 
        return ((key * 2654435761) >> (32 - 16)) % this->one_table_capacity;      
    else {
        hash<Key> hashfunc;
        return (((hashfunc(key)*510) % this->one_table_capacity) * 255) % this->one_table_capacity;
    }
}
template <typename Key, typename Value>
void Cuckoo<Key, Value>::rehash() {
    Pair* temp1 = this->table1;
    Pair* temp2 = this->table2;
    bool* temp3 = this->occupied1;
    bool* temp4 = this->occupied2;
    int temp_capacity = this->capacity;
    int temp_one_capacity = this->one_table_capacity;
    this->capacity *= 2;
    this->one_table_capacity *= 2;
    this->size = 0;
    this->table1 = new Pair[this->one_table_capacity];
    this->table2 = new Pair[this->one_table_capacity];
    this->occupied1 = new bool[this->one_table_capacity];
    this->occupied2 = new bool[this->one_table_capacity];
    for (int i = 0; i < this->one_table_capacity; i++) {
        this->occupied1[i] = false;
        this->occupied2[i] = false;
    }
    for (int i = 0; i < temp_one_capacity; i++) {
        if (temp3[i]) 
            this->insert(temp1[i].first, temp1[i].second);
        if (temp4[i]) 
            this->insert(temp2[i].first, temp2[i].second);
    }
    delete[] temp1;
    delete[] temp2;
    delete[] temp3;
    delete[] temp4;
}
template <typename Key, typename Value>
void Cuckoo<Key, Value>::insert(const Key& key, const Value& value) {
    if (this->isFull())
        this->rehash();
    int index1 = this->hash1(key);
    int index2 = this->hash2(key);
    if (!this->occupied1[index1]) {
        this->table1[index1] = make_pair(key, value);
        this->occupied1[index1] = true;
        this->size++;
        return;
    }
    else if (!this->occupied2[index2]) {
        this->table2[index2] = make_pair(key, value);
        this->occupied2[index2] = true;
        this->size++;
        return;
    }
    Pair temp = make_pair(key, value);
    int currentTable = 1;
    int iterations = 0;

    while (iterations < this->capacity) {
        if (currentTable == 1) {
            swap(temp, this->table1[index1]);
            currentTable = 2;
            index2 = this->hash2(temp.first);
            if (!this->occupied2[index2]) {
                this->table2[index2] = temp;
                this->occupied2[index2] = true;
                this->size++;
                return;
            }
        } else {
            swap(temp, this->table2[index2]);
            currentTable = 1;
            index1 = this->hash1(temp.first);
            if (!this->occupied1[index1]) {
                this->table1[index1] = temp;
                this->occupied1[index1] = true;
                this->size++;
                return;
            }
        }
        iterations++;
    }
    this->rehash();
    this->insert(temp.first, temp.second);
}
template <typename Key, typename Value>
void Cuckoo<Key, Value>::remove(const Key& key) {
    int index1 = this->hash1(key);
    int index2 = this->hash2(key);
    if (this->occupied1[index1] && this->table1[index1].first == key) {
        this->occupied1[index1] = false;
        this->size--;
    }
    else if (this->occupied2[index2] && this->table2[index2].first == key) {
        this->occupied2[index2] = false;
        this->size--;
    }
}
template <typename Key, typename Value>
bool Cuckoo<Key, Value>::search(const Key& key) {
    int index1 = this->hash1(key);
    int index2 = this->hash2(key);
    return (this->occupied1[index1] && this->table1[index1].first == key) || (this->occupied2[index2] && this->table2[index2].first == key);
}
template <typename Key, typename Value>
void Cuckoo<Key, Value>::display() {
    cout << "Table 1:" << endl;
    for (int i = 0; i < this->capacity / 2; i++) 
        if (this->occupied1[i]) 
            cout << this->table1[i].first << " " << this->table1[i].second << endl;
    cout << "Table 2:" << endl;
    for (int i = 0; i < this->capacity / 2; i++) 
        if (this->occupied2[i]) 
            cout << this->table2[i].first << " " << this->table2[i].second << endl;
}
template <typename Key, typename Value>
Value Cuckoo<Key, Value>::get(const Key& key){
    size_t index1 = hash1(key);
    size_t index2 = hash2(key);
    if (occupied1[index1] && table1[index1].first == key)
        return table1[index1].second;
    if (occupied2[index2] && table2[index2].first == key) 
        return table2[index2].second;
    return Value();
}