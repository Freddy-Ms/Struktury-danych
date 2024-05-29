#include"Cuckoo.hpp"
#include<type_traits>
#include<string>
#pragma once

template <typename Key, typename Value>
Cuckoo<Key, Value>::Cuckoo(int capacity) {
    static_assert(is_same<Key, int>::value || is_same<Key, string>::value, "Key must be int or string");
    this->one_table_capacity = capacity;
    this->capacity = 2*capacity;
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
int Cuckoo<Key, Value>::hash1(Key key) {
    if constexpr (is_same<Key, int>::value) {
        return key % this->capacity;
    }
    else {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % this->capacity;
        }
        return hash;
    }
}
template <typename Key, typename Value>
int Cuckoo<Key, Value>::hash2(Key key) {
    if constexpr (is_same<Key, int>::value) {
        return (key / this->capacity) % this->capacity;
    }
    else {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % this->capacity;
        }
        return (hash / this->capacity) % this->capacity;
    }
}
template <typename Key, typename Value>
void Cuckoo<Key, Value>::rehash() {
    Pair* temp1 = this->table1;
    Pair* temp2 = this->table2;
    bool* temp3 = this->occupied1;
    bool* temp4 = this->occupied2;
    int* temp_capacity = this->capacity;
    int* temp_one_capacity = this->one_table_capacity;
    this->capacity *= 2;
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
        if (temp3[i]) {
            this->insert(temp1[i].first);
        }
        if (temp4[i]) {
            this->insert(temp2[i].first);
        }
    }
    delete[] temp1;
    delete[] temp2;
    delete[] temp3;
    delete[] temp4;
    delete temp_capacity;
    delete temp_one_capacity;
}
template <typename Key, typename Value>
void Cuckoo<Key, Value>::insert(Key key, Value value) {
    if (this->isFull()) {
        this->rehash();
    }
    int index1 = this->hash1(key);
    int index2 = this->hash2(key);
    if (!this->occupied1[index1]) {
        this->table1[index1] = make_pair(key, value);
        this->occupied1[index1] = true;
        this->size++;
    }
    else if (!this->occupied2[index2]) {
        this->table2[index2] = make_pair(key, value);
        this->occupied2[index2] = true;
        this->size++;
    }
    else {
        Pair *temp = this->table1[index1];
        this->table1[index1] = make_pair(key, value);
        int iterations = 0;
        while (iterations < this->capacity) {
            index2 = this->hash2(temp.first);
            if (!this->occupied2[index2]) {
                this->table2[index2] = temp;
                this->occupied2[index2] = true;
                this->size++;
                break;
            }
            Pair* temp2 = this->table2[index2];
            this->table2[index2] = temp;
            temp = temp2;
            delete temp2;
        }
        if (iterations == this->capacity) {
            this->rehash();
            this->insert(temp.first, temp.second);
        }
        delete temp;
    }
}
template <typename Key, typename Value>
void Cuckoo<Key, Value>::remove(Key key) {
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
bool Cuckoo<Key, Value>::search(Key key) {
    int index1 = this->hash1(key);
    int index2 = this->hash2(key);
    return (this->occupied1[index1] && this->table1[index1].first == key) || (this->occupied2[index2] && this->table2[index2].first == key);
}
template <typename Key, typename Value>
void Cuckoo<Key, Value>::display() {
    cout << "Table 1:" << endl;
    for (int i = 0; i < this->capacity / 2; i++) {
        if (this->occupied1[i]) {
            cout << this->table1[i].first << " " << this->table1[i].second << endl;
        }
    }
    cout << "Table 2:" << endl;
    for (int i = 0; i < this->capacity / 2; i++) {
        if (this->occupied2[i]) {
            cout << this->table2[i].first << " " << this->table2[i].second << endl;
        }
    }
}
