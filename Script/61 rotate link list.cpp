以下為rotate link list

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
    vector<int> vec = {1, 2, 3, 4, 5};
    ListNode* head = crelink(vec);
    int n = 5;
    int sym = 0;
    ListNode* cur1 = head;
    ListNode* cur2 = head;
    int idx;
    for (idx = 0; idx < n; idx++)
    {
        if (!(cur2 -> next))
        {
            n = n % (idx + 1);
            sym = 1;
            break;
        }
        cur2 = cur2 -> next;
    }
    while(cur2 -> next)
    {
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    if (sym = 1)
    {
        for (int jdx = 0; jdx < (idx - n); jdx++)
        {
            cur1 = cur1 -> next;
        }
    }
    cur2 -> next = head;
    head = cur1 -> next;
    cur1 -> next = nullptr;

    // cout << cur1 -> val << " ";
    // cout << cur2 -> val;
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