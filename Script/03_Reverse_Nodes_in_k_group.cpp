
#include <vector>
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Define the LinkedList class
class LinkedList {
private:
    // Node* head;
    
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    // Insert a new node at the end of the list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Display the elements of the list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};



int main()
{
    LinkedList ll;
    for (int idx = 1; idx < 15; idx++)
    {
        ll.insert(idx);
    }
    
    
    
    
    int numct = 0;
    Node* tmp;
    Node * cur = ll.head;
    while(cur != nullptr)
    {
        numct++;
        cur = cur -> next;
    }

    int nuepoch = numct / 3;
    
    
    
    
    
    int epoch = 0;
    cur = ll.head; 
    Node * prev = nullptr;
    
    Node * connect;
    while(epoch < nuepoch)
        {
            Node* first = cur;
            
            
            int count = 1;
             while(count <= 3)
             {
                 tmp = cur -> next;
                 cur -> next = prev;
                 prev = cur;
                 cur = tmp;
                 count++;
                 
             }
             if (epoch == 0) 
            {
                ll.head = prev;
                
            }
            else
            {
                connect -> next = prev;
            }
            connect = first;
            
            
            
            epoch++;
            
            prev = nullptr;
               
        
        }
        connect -> next = tmp;
        
    
    ll.display();
    
    

    return 0;
}