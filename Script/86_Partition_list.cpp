
//86. Partition List

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
    vector<int> vec = {5, 4, 3, 2, 5, 2};
    
    
    int x = 3;
    ListNode * head = crelink(vec);
    
    
    if (!head)
    {
        return head;
    }
    else if (!head -> next)
    {
        return head;
    }
    
    ListNode* head2 = new ListNode(0);
    ListNode* cur = head;
    ListNode* cur2 = head2;
    
    if (head -> val < x) // head 維持的是小的
    {
        while(cur -> next)
        {
            if (cur -> next -> val >= x)
            {
                ListNode* tmp = cur -> next;
                if (cur -> next -> next)
                {
                    cur -> next = cur -> next -> next;
                    
                    cur2 -> next = tmp;
                    cur2 = cur2 -> next;
                }
                else
                {
                    cur2 -> next = tmp;
                    cur -> next = nullptr;
                    cur2 = cur2 -> next;
                }
            }
            else 
            {
                cur = cur -> next;
            }
        }
        cur2 -> next = nullptr;
        head2 = head2 -> next;
        cur -> next = head2;
    }
    else //head 維持的是大的
    {
        while(cur -> next)
        {
            if (cur -> next -> val < x)
                {
                    ListNode* tmp = cur -> next;
                    if (cur -> next -> next)
                    {
                        cur -> next = cur -> next -> next;
                        
                        cur2 -> next = tmp;
                        cur2 = cur2 -> next;
                    }
                    else
                    {
                        cur2 -> next = tmp;
                        cur -> next = nullptr;
                        cur2 = cur2 -> next;
                    }
                }
            else 
            {
                cur = cur -> next;
            }
        }
        cur2 -> next = head;
        head2 = head2 -> next;
        head = head2;
    }
    // cur2 -> next = nullptr;
    // head2 = head2 -> next;
    // display(head);
    // cout << endl;
    // display(head2);
    
    
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