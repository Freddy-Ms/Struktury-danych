#include"Cuckoo.cpp"
#include "HashMap.cpp"
#include "HashTable.cpp"
#include <fstream>
#include <random>
#include <chrono>


const int size[] = {100, 1000, 10000, 100000, 200000, 500000, 1000000};
void generateRandomData(){
    ofstream file;
    file.open("data.txt");
    for(int i = 0; i < 1000000; i++) {
        file << rand() << " " << rand() << endl;
    }
    file.close();

}
void TestWithHalfCapacity() {
    for(int i = 0; i < 7; i++) {
    std::chrono::high_resolution_clock::time_point Start, End;
    std::chrono::microseconds Elapsed;    
    Cuckoo<int,int> *cuckoo = new Cuckoo<int,int>(size[i]);
    HashMap<int,int> *hashMap = new HashMap<int,int>(size[i]);
    HashTable<int,int> *hashTable = new HashTable<int,int>(100);
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (size[i] / 2); j++) {
        cuckoo->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / (size[i] / 2) << " microseconds" << endl; // no conflict
    cout << "Time taken by Cuckoo Hashing with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (size[i] / 2); j++) {
        hashMap->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / (size[i] / 2)<< " microseconds" << endl; // no conflict
    cout << "Time taken by HashMap with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (size[i] / 2); j++) {
        hashTable->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / (size[i] / 2) << " microseconds" << endl; // no conflict
    cout << "Time taken by Hash Table with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->insert((size[i]/2)+1,size[i]/2+1);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->insert(size[i]/2,size[i]/2+1);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->insert((size[i]/2)+11,size[i]/2+1);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->remove(size[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->remove(size[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->remove(size[i]/2);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // searching in list for key 
    delete cuckoo;
    delete hashMap;
    delete hashTable;
    }
}

void TestWithFullCapacity(){
    for(int i = 0; i < 7; i++) {
    std::chrono::high_resolution_clock::time_point Start, End;
    std::chrono::microseconds Elapsed;    
    Cuckoo<int,int> *cuckoo = new Cuckoo<int,int>(size[i]);
    HashMap<int,int> *hashMap = new HashMap<int,int>(size[i]);
    HashTable<int,int> *hashTable = new HashTable<int,int>(100);
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < size[i]; j++) {
        cuckoo->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(loading all data avg): " << size[i] << " with full size:" << Elapsed.count() / size[i] << " microseconds" << endl; // no conflict
    cout << "Time taken by Cuckoo Hashing with capacity(loading all data): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < size[i]; j++) {
        hashMap->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(loading all data avg): " << size[i] << " with full size:" << Elapsed.count() / size[i] << " microseconds" << endl; // no conflict
    cout << "Time taken by HashMap with capacity(loading all data): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < size[i]; j++) {
        hashTable->insert(j,j);
    }
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(loading all data avg): " << size[i] << " with full size:" << Elapsed.count() / size[i] << " microseconds" << endl; // no conflict
    cout << "Time taken by HashTable with capacity(loading all data): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->insert(size[i]+1,size[i]+1);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(insert with rehashing): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->insert(size[i]+1,size[i]+1);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(insert with rehashing): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->insert(size[i]+1,size[i]+1);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(insert): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->remove(size[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(remove): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->remove(size[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(remove): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->remove(size[i]);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(remove): " << size[i] << " with full size:" << Elapsed.count() << " microseconds" << endl; // searching in list for key
    }
}

void TestWithHalfCapacityRANDOM()
{
   for(int i = 0; i < 7; i++) {
    std::chrono::high_resolution_clock::time_point Start, End;
    std::chrono::microseconds Elapsed;    
    Cuckoo<int,int> *cuckoo = new Cuckoo<int,int>(size[i]);
    HashMap<int,int> *hashMap = new HashMap<int,int>(size[i]);
    HashTable<int,int> *hashTable = new HashTable<int,int>(100);
    Start = std::chrono::high_resolution_clock::now();
    fstream file;
    file.open("data.txt");
    int key, value;
    for(int j = 0; j < (size[i] / 2); j++) {
        file >> key >> value;
        cuckoo->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    file.seekg(0, ios::beg);
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / (size[i] / 2) << " microseconds" << endl; // no conflict
    cout << "Time taken by Cuckoo Hashing with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (size[i] / 2); j++) {
        file >> key >> value;
        hashMap->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    file.seekg(0, ios::beg);
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / (size[i] / 2)<< " microseconds" << endl; // no conflict
    cout << "Time taken by HashMap with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < (size[i] / 2); j++) {
        file >> key >> value;
        hashTable->insert(key,value);
    }
    file.seekg(0, ios::beg);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / (size[i] / 2) << " microseconds" << endl; // no conflict
    cout << "Time taken by Hash Table with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    file >> key >> value;
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // searching in list for key 
    delete cuckoo;
    delete hashMap;
    delete hashTable;
    } 
}

void TestWithFullCapacityRANDOM()
{
   for(int i = 0; i < 7; i++) {
    std::chrono::high_resolution_clock::time_point Start, End;
    std::chrono::microseconds Elapsed;    
    Cuckoo<int,int> *cuckoo = new Cuckoo<int,int>(size[i]);
    HashMap<int,int> *hashMap = new HashMap<int,int>(size[i]);
    HashTable<int,int> *hashTable = new HashTable<int,int>(100);
    Start = std::chrono::high_resolution_clock::now();
    fstream file;
    file.open("data.txt");
    int key, value;
    for(int j = 0; j < size[i]; j++) {
        file >> key >> value;
        cuckoo->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    file.seekg(0, ios::beg);
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / size[i] << " microseconds" << endl; // no conflict
    cout << "Time taken by Cuckoo Hashing with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < size[i] ; j++) {
        file >> key >> value;
        hashMap->insert(key,value);
    }
    End = std::chrono::high_resolution_clock::now();
    file.seekg(0, ios::beg);
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / size[i] << " microseconds" << endl; // no conflict
    cout << "Time taken by HashMap with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < size[i] ; j++) {
        file >> key >> value;
        hashTable->insert(key,value);
    }
    file.seekg(0, ios::beg);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(loading all data avg): " << size[i] << " with half size:" << Elapsed.count() / size[i]  << " microseconds" << endl; // no conflict
    cout << "Time taken by Hash Table with capacity(loading all data): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    file >> key >> value;
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->insert(key,value);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(insert): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    cuckoo->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Cuckoo Hashing with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashMap->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Map with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // no conflict
    Start = std::chrono::high_resolution_clock::now();
    hashTable->remove(key);
    End = std::chrono::high_resolution_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
    cout << "Time taken by Hash Table with capacity(remove): " << size[i] << " with half size:" << Elapsed.count() << " microseconds" << endl; // searching in list for key 
    delete cuckoo;
    delete hashMap;
    delete hashTable;
    } 
}