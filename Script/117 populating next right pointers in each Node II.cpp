// 117 populating next right pointers in each Node II
// 兩個解 一個是RECURENCE 一個是ITERATION
#include <iostream>
#include <vector>
using namespace std;
 
 
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
 
 
class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root)
        {
            return root;
        }
        if (!root -> left && !root -> right)
        {
            return root;
        }
        if (root -> left && root -> right)
        {
            root -> left -> next = root -> right;
            Node* next;
            if (root -> next)
            {
                int sym = 0;
                Node* cur = root;
                while(cur -> next)
                {
                    cur = cur -> next;
                    if (cur -> left)
                    {
                        cur = cur -> left;
                        sym = 1;
                        break;
                    }
                    if (cur -> right)
                    {
                        cur = cur -> right;
                        sym = 1;
                        break;
                    }
                }
                if (sym == 1)
                {
                    root -> right -> next = cur;
                }
            }
        }
        else if (root -> left && !root -> right)
        {
            Node* next;
            if (root -> next)
            {
                int sym = 0;
                Node* cur = root;
                while(cur -> next)
                {
                    cur = cur -> next;
                    if (cur -> left)
                    {
                        cur = cur -> left;
                        sym = 1;
                        break;
                    }
                    if (cur -> right)
                    {
                        cur = cur -> right;
                        sym = 1;
                        break;
                    }
                }
                if (sym == 1)
                {
                    root -> left -> next = cur;
                }
            }
        }
        else if (!root -> left && root -> right)
        {
            Node* next;
            if (root -> next)
            {
                int sym = 0;
                Node* cur = root;
                while(cur -> next)
                {
                    cur = cur -> next;
                    if (cur -> left)
                    {
                        cur = cur -> left;
                        sym = 1;
                        break;
                    }
                    if (cur -> right)
                    {
                        cur = cur -> right;
                        sym = 1;
                        break;
                    }
                }
                if (sym == 1)
                {
                    root -> right -> next = cur;
                }
            }
        }
        Node* dummy = connect(root -> right);
        dummy = connect(root -> left);
        return root;
    }
    Node* connect2(Node* root)
    {
        Node* cur;
        vector<Node*> q = {root};
        while(q.size() > 0)
        {
            vector<Node*> q2 = {};
            for (int idx = 0; idx < q.size(); idx++)
            {
                cur = q[idx];
                if (idx < q.size() - 1)
                {
                    cur -> next = q[idx + 1];
                }
                if (cur -> left)
                {
                    q2.push_back(cur -> left);
                }
                if (cur -> right)
                {
                    q2.push_back(cur -> right);
                }
            }
            q = q2;
        }
        return root;

    }
};
 
Node* make_tree(vector<int> vec);
int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -4, -4, -4, -4, 14};
    vec = {2, 1, 3, 0, 7, 9, 1, -4, -4, -4, 1, -4, -4, 5, -4};
    Node* root = make_tree(vec);
    Solution abc;
    abc.connect2(root);
    // cout << root -> right->right-> right -> val;
    Node* cur = root ->left -> right;
    if (cur -> next)
    {
        cout << cur -> next -> val;
    }
    else
    {
        cout << "NULL";
    }
    return 0;
}
Node* make_tree(vector<int> vec)
{
    Node* root = new Node(vec[0]);

    int nod = 2;
    int cur = 1;
    Node* cur_node;
    vector<Node*> this_list = {root}; 
    vector<Node*> next_list = {};
    while((cur - 1) + nod <= vec.size())
    {
        for (int idx = 0; idx < nod / 2; idx++)
        {
            // q.push_back(vec[cur]);
            cur_node = this_list[idx];
            if (cur_node -> val != -4)
            {
                if (vec[cur] != -4)
                {
                    cur_node -> left = new Node(vec[cur]);
                    next_list.push_back(cur_node -> left);
                }
                else
                {
                    next_list.push_back(new Node(-4));
                }
                cur++;
                if (vec[cur] != -4)
                {
                    cur_node -> right = new Node(vec[cur]);
                    next_list.push_back(cur_node -> right);
                }
                else
                {
                    next_list.push_back(new Node(-4));
                }
            }
            else
            {
                cur++;
            }
            cur++;
        }
        this_list = next_list;
        next_list = {};
        nod = nod * 2;
    }
    return root;
}