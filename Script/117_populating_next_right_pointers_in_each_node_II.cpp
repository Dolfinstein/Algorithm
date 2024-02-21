/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//117. Populating Next Right Pointers in Each Node II
#include <iostream>
#include <queue>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
Node* connect(Node* root);

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> right = new Node(7);
    
    root = connect(root);
    
    cout << root -> left -> next -> val;

    return 0;
}
Node* connect(Node* root)
{
    if (!root)
    {
        return root;
    }
    if ((!(root -> left)) && (!(root -> right)))
    {
        return root;
    }
    
    queue<Node*> q;
    q.push(root);
    int count;
    int count2 = 1;
    while(q.size() > 0)
    {
        count = count2;
        count2 = 0;
        for (int idx = 0; idx < count; idx++)
        {
            Node* tmp;
            tmp = q.front();
            q.pop();
            if (idx < count - 1)
            {
                tmp -> next = q.front();
            }
            if (tmp -> left)
            {
                q.push(tmp -> left);
                count2++;
            }
            if (tmp -> right)
            {
                q.push(tmp -> right);
                count2++;
            }
        }
    }
    
    return root;
}