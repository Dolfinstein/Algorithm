// 114. Flatten Binary Tree to Linked List
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 注意裡面的第二個做法其實是vlr traverse of the binary tree
//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

vector<int> flatten2(TreeNode* root);
void flatten(TreeNode* root);

int main()
{
    
    
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(5);
    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(4);
    root -> right -> right = new TreeNode(6);
    // root -> left -> right -> left = new TreeNode(11);
    
    
    flatten(root);
    TreeNode* cur = root;
    cout << root -> left -> val;
    // while(true)
    // {
    //     cout << cur -> val << " ";
    //     if (cur -> right)
    //     {
    //         cur = cur -> right;
    //     }
    //     else
    //     {
    //         break;
    //     }
        
    // }
    
    return 0;
}


void flatten(TreeNode* root)
{
    if (!root)
    {
        return;
    }
    
    TreeNode* right_half = root -> right;
    
    stack<TreeNode*> stack;
    TreeNode* cur = root;
    TreeNode* cur2 = root;
    if (cur -> left)
    {
        cur = cur -> left;
        while(true)
    
        {
            TreeNode* tmpleft = cur -> left;
            if (cur -> right)
            {
                stack.push(cur -> right);
            }
            cur2 -> right = cur;
            cur2 -> left = nullptr;
            cur2 = cur2 -> right;
            
            if (tmpleft)
            {
                cur = tmpleft;
            }
            else
            {
                if (stack.size() == 0)
                {
                    break;
                }
                cur = stack.top();
                stack.pop();
            }
        }
    }
    
    if (right_half)
    {
        root -> left = right_half;
        cur = root -> left;
        while(true)
    
        {
            TreeNode* tmpleft = cur -> left;
            if (cur -> right)
            {
                stack.push(cur -> right);
            }
            cur2 -> right = cur;
            cur2 -> left = nullptr;
            cur2 = cur2 -> right;
            
            if (tmpleft)
            {
                cur = tmpleft;
            }
            else
            {
                if (stack.size() == 0)
                {
                    break;
                }
                cur = stack.top();
                stack.pop();
            }
        }
        
    }
    
    
    
    
    
    
    
    return;
    
    
    
    
    
    
    
}
vector<int> flatten2(TreeNode* root)
{
    vector<int> test;
    
    stack<TreeNode*> stack;
    TreeNode* cur = root;
    TreeNode* cur2 = root;
    
    test.push_back(root -> val);
    
    while(true)
    {
        stack.push(cur);
        if (cur -> left)
        {
            cur = cur -> left;
            
            test.push_back(cur -> val);
            // TreeNode* tmp = cur2 -> right;
            // cur2 -> right = new TreeNode(cur -> val);
            // cur2 = cur2 -> right;
            // cur2 -> right = tmp;
            
        }
        else
        {
            while(true)
            {
                if (stack.size() == 0)
                {
                    return test;
                }
                cur = stack.top();
                stack.pop();
                if (cur -> right)
                {
                    break;
                }
            }
            cur = cur -> right;
            test.push_back(cur -> val);
        }
    }
}