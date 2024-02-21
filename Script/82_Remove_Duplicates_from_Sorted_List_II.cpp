
//82_Remove_Duplicates_from_Sorted_List_II

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
    vector<int> vec = {1, 2, 3, 3, 4, 4, 5, 6};
    
    int sym = 0;
    ListNode * head = crelink(vec);
    ListNode * dummy = new ListNode(-1);
    
    dummy -> next = head;
    head = dummy;
    ListNode *cur = head;
    ListNode* tmp;
    
    
    
    while(cur -> next)
    {
        if (!(cur -> next -> next))
        {
            head = head -> next;
            display(head);
            exit(0);
        }
        if (cur -> next -> next -> val == cur -> next -> val)
        {
            tmp = cur -> next;
            while(tmp -> val == cur -> next -> val)
            {
                tmp = tmp -> next;
                if (!tmp)
                {
                    sym = 1;
                    break;
                }
            }
            if (sym == 1)
            {
                cur -> next = nullptr;
                head = head -> next;
                display(head);
                exit(0);
            }
            cur -> next = tmp;
        }
        else 
        {
            cur = cur -> next;
        }
    }
    
    head = head -> next;
    display(head);
    exit(0);

    
    
    

   
    
    
    
    
    
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