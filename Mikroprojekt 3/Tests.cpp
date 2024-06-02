#include"Cuckoo.cpp"
#include "HashMap.cpp"
#include "HashTable.cpp"
#include <fstream>
#include <unordered_set>
#include <random>
#include <chrono>


const int sizes[] = {100, 1000, 10000, 100000, 200000, 500000, 1000000};
void generateRandomData() {
    std::ofstream file;
    file.open("data.txt");

    std::unordered_set<int> uniqueKeys;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(1, 1000000000); 

    while (uniqueKeys.size() < 1000001) {
        int key = dis(gen);
        int value = dis(gen);

        if (uniqueKeys.find(key) == uniqueKeys.end()) {
            uniqueKeys.insert(key);
            file << key << " " << value << std::endl;
        }
    }

    file.close();
}
void TestWithHalfCapacity() {
    for(int i = 0; i < 7; i++) {
    std::chrono::high_resolution_clock::time_point Start, End;
    std::chrono::nanoseconds Elapsed;    
    Cuckoo<int,int> *cuckoo = new Cuckoo<int,int>(sizes[i]);
    HashMap<int,int> *hashMap = new HashMap<int,int>(sizes[i]);
    HashTable<int,int> *hashTable = new HashTable<int,int>(100);
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (sizes[i] / 2); j++) {
        cuckoo->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / (sizes[i] / 2) << " ns" << endl; // no conflict
    cout << "Cuckoo Hashing (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (sizes[i] / 2); j++) {
        hashMap->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / (sizes[i] / 2)<< " ns" << endl; // no conflict
    cout << "HashMap (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (sizes[i] / 2); j++) {
        hashTable->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / (sizes[i] / 2) << " ns" << endl; // no conflict
    cout << "Hash Table (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->insert(sizes[i]/2,sizes[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->insert(sizes[i]/2,sizes[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->insert((sizes[i]/2),sizes[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->remove(sizes[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->remove(sizes[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->remove(sizes[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // searching in list for key 
    delete cuckoo;
    delete hashMap;
    delete hashTable;
    }
}

void TestWithFullCapacity(){
    for(int i = 0; i < 7; i++) {
    std::chrono::high_resolution_clock::time_point Start, End;
    std::chrono::nanoseconds Elapsed;    
    Cuckoo<int,int> *cuckoo = new Cuckoo<int,int>(sizes[i]);
    HashMap<int,int> *hashMap = new HashMap<int,int>(sizes[i]);
    HashTable<int,int> *hashTable = new HashTable<int,int>(100);
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < sizes[i]; j++) {
        cuckoo->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / sizes[i] << " ns" << endl; // no conflict
    cout << "Cuckoo Hashing (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < sizes[i]; j++) {
        hashMap->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / sizes[i] << " ns" << endl; // no conflict
    cout << "HashMap (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < sizes[i]; j++) {
        hashTable->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / sizes[i] << " ns" << endl; // no conflict
    cout << "HashTable (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->insert(sizes[i],sizes[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (insert with rehashing): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->insert(sizes[i],sizes[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (insert with rehashing): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->insert(sizes[i],sizes[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->remove(sizes[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->remove(sizes[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->remove(sizes[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // searching in list for key
    delete cuckoo;
    delete hashMap;
    delete hashTable;
    }
}

void TestWithHalfCapacityRANDOM()
{
   for(int i = 0; i < 7; i++) {
    std::chrono::high_resolution_clock::time_point Start, End;
    std::chrono::nanoseconds Elapsed;    
    Cuckoo<int,int> *cuckoo = new Cuckoo<int,int>(sizes[i]);
    HashMap<int,int> *hashMap = new HashMap<int,int>(sizes[i]);
    HashTable<int,int> *hashTable = new HashTable<int,int>(100);
    Start = std::chrono::high_resolution_clock::now();
    fstream file;
    file.open("data.txt");
    int key, value;
    for(int j = 0; j < (sizes[i] / 2); j++) {
        file >> key >> value;
        cuckoo->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    file.seekg(0, ios::beg);
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / (sizes[i] / 2) << " ns" << endl; // no conflict
    cout << "Cuckoo Hashing (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (sizes[i] / 2); j++) {
        file >> key >> value;
        hashMap->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    file.seekg(0, ios::beg);
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / (sizes[i] / 2)<< " ns" << endl; // no conflict
    cout << "HashMap (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (sizes[i] / 2); j++) {
        file >> key >> value;
        hashTable->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / (sizes[i] / 2) << " ns" << endl; // no conflict
    cout << "Hash Table (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    file >> key >> value;
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // searching in list for key 
    delete cuckoo;
    delete hashMap;
    delete hashTable;
    } 
}

void TestWithFullCapacityRANDOM()
{
   for(int i = 0; i < 7; i++) {
    std::chrono::high_resolution_clock::time_point Start, End;
    std::chrono::nanoseconds Elapsed;    
    Cuckoo<int,int> *cuckoo = new Cuckoo<int,int>(sizes[i]);
    HashMap<int,int> *hashMap = new HashMap<int,int>(sizes[i]);
    HashTable<int,int> *hashTable = new HashTable<int,int>(100);
    Start = std::chrono::high_resolution_clock::now();
    fstream file;
    file.open("data.txt");
    int key, value;
    for(int j = 0; j < sizes[i]; j++) {
        file >> key >> value;
        cuckoo->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    file.seekg(0, ios::beg);
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / sizes[i] << " ns" << endl; // no conflict
    cout << "Cuckoo Hashing (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < sizes[i] ; j++) {
        file >> key >> value;
        hashMap->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    file.seekg(0, ios::beg);
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / sizes[i] << " ns" << endl; // no conflict
    cout << "HashMap (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < sizes[i] ; j++) {
        file >> key >> value;
        hashTable->insert(key,value);
    }
    file.seekg(0, ios::beg);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (loading all data avg): " << sizes[i] << "\t" << Elapsed.count() / sizes[i]  << " ns" << endl; // no conflict
    cout << "Hash Table (loading all data): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    file >> key >> value;
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (insert): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Cuckoo Hashing (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Map (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    cout << "Hash Table (remove): " << sizes[i] << "\t" << Elapsed.count() << " ns" << endl; // searching in list for key 
    delete cuckoo;
    delete hashMap;
    delete hashTable;
    } 
}