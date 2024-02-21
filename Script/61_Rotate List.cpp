
//61. Rotate List

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;




// Definition for a Node.

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

 
ListNode* crelink(vector<int> vec);
void display(ListNode * head);



int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    
    int k = 6;
    ListNode * head = crelink(vec);
    ListNode* cur = head;


    if (!head)
    {
        return head;
    }
    else if (!head -> next)
    {
        return head;
    }
    else if (k == 0)
    {
        return head;
    }
    
    
    ListNode* left = head;
    ListNode* right = head;
    int sym = 0;
    int count = 1;
    for (int idx = 0; idx < k; idx++)
    {
        if (!right -> next)
        {
            sym = 1;
            break;
        }
        right = right -> next;
        count++;
        
    }
    // cout << count;
    
    if (sym == 1)
    {
        if (k % count == 0)
        {
            display(head);
            exit(0);
        }
        else
        {
            k = k % count;    
            count = count - k - 1;
            for (int idx = 0; idx < count; idx++)
            {
                left = left -> next;
            }
        }
    }
    else
    {
        while(right -> next)
        {
            right = right -> next;
            left = left -> next;
        }
    }
    ListNode* tmp = left -> next;
    right -> next = head;
    left -> next = nullptr;
    head = tmp;
    
    display(head);
    
    
    
    
    
    
    
    
    

   
    
    
    
    
    
    return 0;
}
ListNode* crelink(vector<int> vec)
{
    ListNode* head;
    ListNode* cur;
    for (int idx = 0; idx < vec.size(); idx++)
    {
        if (idx == 0)
        {
            head = new ListNode(vec[0]);
            cur = head;
        }
        else
        {
            cur -> next = new ListNode(vec[idx]);
            cur = cur -> next;
        }
    }
    return head;
}

void display(ListNode * head)
{
    ListNode * cur = head;
    while(cur)
    {
        cout << cur -> val << "->";
        cur = cur -> next;
    }
    cout << "NULL";
}