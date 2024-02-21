
//38. Copy List with Random Pointer

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
    vector<int> vec = {1, 2, 4,8,10};
    
    ListNode* list1 = crelink(vec);
    vec = {1, 3, 4};
    ListNode* list2 = crelink(vec);
    
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;
    ListNode* head;
    if (cur1 -> val <= cur2 -> val)
    {
        head = cur1;
        cur1 = cur1 -> next;
    }
    else 
    {
        head = cur2;
        cur2 = cur2 -> next;
    }
    ListNode* cur = head;
    ListNode* tmp;
    while(cur1 && cur2)
    {
        if (cur1 -> val <= cur2 -> val)
        {
            if (cur -> next == cur1)
            {
                cur1 = cur1 -> next;
                cur = cur -> next;
            }
            else
            {
                cur -> next = cur1;
                cur1 = cur1 -> next;
                cur = cur -> next;
            }
        }
        else //cur1 -> val > cur2 -> val
        {
            if (cur -> next == cur2)
            {
                cur = cur -> next;
                cur2 = cur2 -> next;
            }
            else
            {
                cur -> next = cur2;
                cur2 = cur2 -> next;
                cur = cur -> next;
            }
        }
    }
    
    if (cur1 && !cur2)
    {
        cur -> next = cur1;
    }
    else if (cur2 && !cur1)
    {
        cur -> next = cur2;
    }
    
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