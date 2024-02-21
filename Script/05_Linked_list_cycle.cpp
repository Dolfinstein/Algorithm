
#include <iostream>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;     ListNode(int x) : val(x), next(NULL) {}
};


int main()
{
    ListNode* head;
    ListNode* cur = head;
    for (int idx = 0; idx < 4; idx++)
    {
        cur = new ListNode(idx);
        cur = cur -> next;
    }

    cur = head;

    for (int idx = 0; idx < 4; idx++)
    {
        cout << cur -> val << "->";
        cur = cur -> next;
    }
    cout << "nullptr";

    return 0;
}