//100. Same Tree
// this is bfs.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
  
TreeNode* dfs_copy(TreeNode* root);
bool chksame(TreeNode* root1, TreeNode* root2);
 
int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* cur1 = root;
    cur1 -> left = new TreeNode(9);
    cur1 -> right = new TreeNode(20);
    TreeNode* cur2 = cur1 -> left;
    TreeNode * cur3 = cur1 -> right;
    
    cur3 -> left = new TreeNode(15);
    cur3 -> right = new TreeNode(7);
    
    
    
    TreeNode* root2 = dfs_copy(root);
    
    
    
    
    
    bool ans = chksame(root, root2);
    
    cout << ans;

    return 0;
}

TreeNode* dfs_copy(TreeNode* root)
{
    TreeNode* root2 = new TreeNode(root -> val);
    TreeNode* l;
    TreeNode* r;
    if (root -> left)
    {
        l = dfs_copy(root -> left);
        root2 -> left = l;
    }
    if (root -> right)
    {
        r = dfs_copy(root -> right);
        root2 -> right = r;
    }
    
    return root2;
    
    
}


bool chksame(TreeNode* root1, TreeNode* root2)
{
    if (!(root1) && !(root2))
    {
        return true;
    }
    else if (root1 && root2)
    {
        
    }
    else 
    {
        return false;
    }
    
    if (!(root1 -> left) && !(root1 -> right))
    {
        if (!(root2 -> left) && !(root2 -> right))
        {
            if (root1 -> val == root2 -> val)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        else 
        {
            return false;
        }
    }
    
    
    if (root1 -> val != root2 -> val)
    {
        return false;
    }
    
    
    queue<TreeNode*> que1 = {};
    queue<TreeNode*> que2 = {};
    
    que1.push(root1);
    que2.push(root2);
    
    int size = 1;
    int size2 = size;
    while(size2 > 0)
    {
        for (int idx = 0; idx < size2; idx++)
        {
            TreeNode* tmp1 = que1.front();
            TreeNode* tmp2 = que2.front();
            
            que1.pop();
            que2.pop();
            size--;
            
            if (tmp1 -> left && tmp2 -> left)
            {
                if (tmp1 -> left -> val != tmp2 -> left -> val)
                {
                    return false;
                }
                else
                {
                    que1.push(tmp1 -> left);
                    que2.push(tmp2 -> left);
                    size++;
                }
            }
            else if (!(tmp1 -> left) && !(tmp2 -> left))
            {
                
            }
            else 
            {
                return false;
            }
            if (tmp1 -> right && tmp2 -> right)
            {
                if (tmp1 -> right -> val != tmp2 -> right -> val)
                {
                    return false;
                }
                else 
                {
                    que1.push(tmp1 -> right);
                    que2.push(tmp2 -> right);
                    size++;
                }
            }
            else if (!(tmp1 -> right) && !(tmp2 -> right))
            {
                
            }
            else 
            {
                return false;
            }
            
        }
        size2 = size;
        
        
    }
    return true;
    
    
    
    
}