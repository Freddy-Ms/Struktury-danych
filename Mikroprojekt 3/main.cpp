#include"Cuckoo.cpp"
#include"HashTable.cpp"
int main()
{
   Cuckoo<int, int> c(10);
   HashTable<int, int> h(10);
   for(int i = 0; i < 10;i++)
   {
    //  c.insert(i, i);
      h.insert(i, i);
   }
   //c.display();
   //cout << c.search(5) << endl;
   h.display();
   cout << h.get_size() << endl;
   h.insert(1,1);
}