#include<iostream>
#include"Queue.hpp"
using namespace std;


template <typename T>
class ListQueue : public Queue<T>
{
    private:
        struct Node
        {
            T data;
            int priority;
            Node* next;
            Node* prev;
            Node(T data, int priority, Node* next = nullptr, Node* prev = nullptr) : data(data), priority(priority), next(next), prev(prev) {}
        };
        Node* head;
        Node* tail;
        int actualsize;
        void repair(){
            Node* node = head;
            while(node->next != nullptr && node->priority >= node->next->priority){
                swap(node->data, node->next->data);
                swap(node->priority, node->next->priority);
                node = node->next;
            }
        }
        void repairForward(Node* start){
            Node* node = start;
            while(node->next != nullptr && node->priority >= node->next->priority){
                swap(node->data, node->next->data);
                swap(node->priority, node->next->priority);
                node = node->next;
            }
        }
        void repairBackward(Node* start){
            Node* node = start;
            while(node->prev != nullptr && node->priority < node->prev->priority){
                swap(node->data, node->prev->data);
                swap(node->priority, node->prev->priority);
                node = node->prev;
            }}

        
    public:
    ListQueue() : head(nullptr), tail(nullptr), actualsize(0) {}
    ~ListQueue(){
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    virtual void add(T element, int priority) override{
        Node* node = new Node(element, priority,head,nullptr);
        if(head == nullptr){
            head = node;
            tail = node;
        }else{
            
            head->prev = node;
            head = node;
        }
        repair();
        actualsize++;
    }
    virtual T getHighest() override{
        if(head == nullptr)
            throw runtime_error("Queue is empty");
        Node* temp = head;
        T data = head->data;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return data;
    }
    virtual void getSize() override{
        cout << "Size of our queue is: " << actualsize << endl;
    }
    virtual void peek() override{
        if(head == nullptr)
            throw runtime_error("Queue is empty");
        cout << "First element in our queue is: " << head->data << endl;
    }
    virtual void printData() override{
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    virtual void printPriority() override{
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->priority << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    virtual void ReadFile(string filename) override{
        ifstream file;
        file.open(filename);
        if(!file.is_open())
            throw runtime_error("File not found");
        T data;
        int priority;
        while(file >> data >> priority)
            add(data, priority);
        file.close();
    }
    virtual void Modify(T element, int newPriority) override
    {
        bool found = false;
        Node* node = head;
        while(node != nullptr){
            if(node->data == element){
                found = true;
                if(node->priority < newPriority){
                    node->priority = newPriority;
                    Node* temp = node;
                    repairForward(temp);
                    }
                else if(node->priority > newPriority){
                    node->priority = newPriority;
                    Node* temp = node;
                    repairBackward(temp);
               }
                }
            node = node->next;
        }
        
        if(!found)
        cout << "Element not found" << endl;
    }
    void ModifyFirst(T element, int newPriority) {
        bool found = false;
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == element){
                found = true;
                if(temp->priority > newPriority){
                    temp->priority = newPriority;
                    repairBackward(temp);}
                else{
                    temp->priority = newPriority;
                    repairForward(temp);
                }
                return;
            }
            temp = temp->next;
        }
        if(!found)
        cout << "Element not found" << endl;
    }
    T getLast(){
        if(tail == nullptr)
            throw runtime_error("Queue is empty");
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        T data = temp->data;
        delete temp;
        return data;
    }
    void peekLast(){
        if(tail == nullptr)
            throw runtime_error("Queue is empty");
        cout << "Last element in our queue is: " << tail->data << endl;
    }
};       