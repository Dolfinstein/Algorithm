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
    for (int idx = 1; idx <= 4; idx++)
    {
        ll.insert(idx);
    }
    int left = 1;
    int right = 2;
    
    if (left != 0 && left != 1)
    {
        Node* cur = ll.head;
        for (int idx = 0; idx < left - 2; idx++)
        {
            cur = cur -> next;
        }
        
        
        
        
        Node* lcon = cur;
        cur = cur -> next;

        
        
        Node* first = cur;
        
        Node* past = nullptr;
        Node* fut = nullptr;
        Node* rcon;
        
        for (int idx = 0; idx < right - left + 1; idx++)
        {
            fut = cur -> next;
            cur -> next = past;
            past = cur;
            // rcon = cur;
            cur = fut;
        }
        
        
        
        first -> next = cur;
        lcon -> next = past;
    }
    
    
    
    else
    {
        Node* cur = ll.head;
        Node* past = nullptr;
        Node* fut = nullptr;
        Node* first = cur;
        for (int idx = 0; idx < right - left; idx++)
        {
            
            fut = cur -> next;
            cur -> next = past;
            past = cur;
            cur = fut;
        }
        first -> next = cur;
        ll.head = past;
        
    }
    
    ll.display();
    
    

    return 0;
}