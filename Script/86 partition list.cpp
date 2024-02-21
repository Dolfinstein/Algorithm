#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode(): val(0), next(nullptr), random(nullptr){}
    ListNode(int x): val(x), next(nullptr), random(nullptr){}
    // ListNode(int x, ListNode *next): val(x), next(next){}


};
ListNode* crelink(vector<int> vec);
void display(ListNode* head);
 
ListNode* sum(ListNode* l1, ListNode* l2);
int main()
{
    vector<int> vec = {4, 1, 3, 2, 5, 2};
    ListNode* head = crelink(vec);
    int x = 3;
    ListNode* pivot = head;
    int sym = 0;
    if (pivot -> val >= x)
    {
        head = new ListNode(x - 1);
        head -> next = pivot;
        pivot = head;
        sym = 1;
    }

    while(pivot -> next -> val < x)
    {
        pivot = pivot -> next;
    }
    ListNode* cur = pivot -> next;

    while(cur -> next)
    {
        if (cur -> next -> val < x)
        {
            ListNode* conn1 = pivot -> next;
            // ListNode* conn2 = cur -> next -> next;
            pivot -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pivot = pivot -> next;
            pivot -> next = conn1;
            // pivot = pivot -> next;
        }
        else
        {
            cur = cur -> next;
        }
    }
    if (sym == 1)
    {
        head = head -> next;
    }

    display(head);

    return 0;
}
 
 
ListNode* crelink(vector<int> vec)
{
    ListNode* head = new ListNode(vec[0]);
    ListNode* cur = head;
    for (int idx = 1; idx < vec.size(); idx++)
    {
        cur -> next = new ListNode(vec[idx]);
        cur = cur -> next;
    }
    return head;
}
 
void display(ListNode* head)
{
    ListNode* cur = head;
    while(cur)
    {
        cout << cur -> val << "->";
        cur = cur -> next;
    }
    cout << "nullptr";
}
 
 
ListNode* sum(ListNode* l1, ListNode* l2)
{
    ListNode* l3 = new ListNode(-1);
    ListNode* cur = l3;
    int add = 0;
    while(true)
    {
        if (l1 && l2)
        {
            if (add == 1)
            {
                cur -> next = new ListNode(1);
            }
            else
            {
                cur -> next = new ListNode(0);
            }
            if (((l1 -> val) + (l2 -> val)) + cur -> next -> val >= 10)
            {
                cur -> next -> val += (((l1 -> val) + (l2 -> val)) % 10);
                add = 1;
            }
            else
            {
                cur -> next -> val += ((l1 -> val) + (l2 -> val));
                add = 0;
            }
            cur = cur -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        else if(!l1 && l2)
        {
            if (add == 1 )
            {
                cur -> next =new ListNode(1);
            }
            else
            {
                cur -> next = new ListNode(0);
            }
            cur -> next -> val +=(l2 -> val);
            add = 0;
            cur = cur -> next;
            l2 = l2 -> next;
        }
        else if (!l2 && l1)
        {
            if (add == 1 )
            {
                cur -> next =new ListNode(1);
            }
            else
            {
                cur -> next = new ListNode(0);
            }
            cur -> next -> val +=(l1 -> val);
            add = 0;
            cur = cur -> next;
            l1 = l1 -> next;
        }
        else
        {
            return l3 -> next;
        }

    }


    return l3;


}