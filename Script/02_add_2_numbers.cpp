
//2. add 2 numbers

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;



struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 void display(ListNode* head);

int main()
{
    
    ListNode *l1 = new ListNode(2);
    l1 -> next = new ListNode(4);
    l1 -> next -> next = new ListNode(5);
    
    ListNode *l2 = new ListNode(5);
    l2 -> next = new ListNode(6);
    l2 -> next -> next = new ListNode(4);
    l2 -> next -> next -> next = new ListNode(9);
    
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    int add = 0;
    ListNode* tmp;
    
    while(cur1 != nullptr || cur2 != nullptr)
    {
        if (cur1 != nullptr && cur2 != nullptr)
        {
            cout << cur1 -> val + cur2 -> val + add;
            cout << endl;
            int value = (cur1 -> val + cur2 -> val + add) % 10;
            // cur1 -> val = (cur1 -> val + cur2 -> val + add) % 10;
            if (((cur1 -> val + cur2 -> val) + add) >= 10)
            {
                add = 1;
            }
            else
            {
                add = 0;
            }
            cur1 -> val = value;
            tmp = cur1;
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
        else if (cur1 != nullptr && cur2 == nullptr)
        {
            int value = (cur1 -> val + add) % 10;
            // cur1 -> val = (cur1 -> val + add) % 10;
            if (cur1 -> val + add >= 10)
            {
                add = 1;
            }
            else
            {
                add = 0;
            }
            cur1 -> val = value;
            tmp = cur1;
            cur1 = cur1 -> next;
        }
        else if (cur1 == nullptr && cur2 != nullptr)
        {
            tmp -> next = new ListNode((cur2 -> val + add) % 10);
            if (cur2 -> val + add >= 10)
            {
                add = 1;
            }
            else
            {
                add = 0;
            }
            tmp = tmp -> next;
            cur2 = cur2 -> next;
        }
    }
    
    if (add == 1)
    {
        tmp -> next = new ListNode(1);
    }
    
    display(l1);
    
    
    return 0;
}

void display(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head -> val;
        head = head -> next;
    }
}
