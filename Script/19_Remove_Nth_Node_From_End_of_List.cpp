

// 19_Remove_Nth_Node_From_End_of_List

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
    int n = 6;
    
    ListNode * head = crelink(vec);
    
    int sym = 0;
    int count = 1;
    ListNode* right = head;
    ListNode* left = head;
    for (int idx = 0; idx < n; idx++)
    {
        count++;
        right = right -> next;
        if (!right)
        {
            count--;
            sym = 1;
            break;
        }
    }
    
    if (count == n)
    {
        head = head -> next;
        display(head);
        exit(0);
    }
    
    if (sym == 1)
    {
        n = n % count;
        
        for (int idx = 0; idx < (count - n - 1); idx++)
        {
            left = left -> next;
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
    
    left -> next = left -> next -> next;
    
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