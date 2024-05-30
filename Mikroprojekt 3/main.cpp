#include"Cuckoo.cpp"
#include"HashTable.cpp"
#include"HashMap.cpp"
int main()
{
   Cuckoo<int, int> c(10);
   HashTable<int, int> h(10);
   HashMap<int, int> m(10);
   m.insert(1, 2);
   m.insert(2, 3);
   m.insert(3, 4);
   m.insert(4, 5);
   m.insert(5, 6);
   m.insert(6, 7);
   m.insert(7, 8);
   m.insert(8, 9);
   m.insert(9, 10);
   m.insert(10, 11);
   m.insert(11, 12);
   cout << endl;
   m.print();
   cout << endl;
   cout << m.search(1) << endl;
   cout << endl;
   m.remove(1);
   m.print();
}