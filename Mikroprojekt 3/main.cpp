#include"Cuckoo.cpp"
int main()
{
   Cuckoo<int, int> c(1);
   c.insert(1, 2);
   c.insert(2, 3);
   c.insert(3, 4);
   c.insert(4, 5);
   c.insert(5, 6);
   c.insert(6, 7);
   c.insert(7, 8);
   c.insert(8, 9);
   c.insert(9, 10);
   c.insert(10, 11);
   c.insert(11, 12);
   c.insert(12, 13);
   c.insert(13, 14);
   c.insert(14, 15);
   c.insert(15, 16);
   c.insert(16, 17);
   c.insert(17, 18);
   c.insert(18, 19);
   c.insert(19, 20);
   c.insert(20, 21);
   c.insert(21, 22);
   c.display();
}