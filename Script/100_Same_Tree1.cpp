
//100. Same Tree
// this is dfs.
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
    if (!root1 && root2)
    {
        return true;
    }
    else if (root1 && root2)
    {
    
        bool l = true;
        bool r = true;
        
        if (root1 -> left && root2 -> left)
        {
            l = chksame(root1 -> left, root2 -> left);
        }
        else if (!(root1 -> left) && !(root2 -> left))
        {
            
        }
        else 
        {
            return false;
        }
        
        if (root1 -> right && root2 -> right)
        {
            r = chksame(root1 -> right, root2 -> right);
        }
        else if (!(root1 -> right) && !(root2 -> right))
        {
            
        }
        else 
        {
            return false;
        }
        
        
        
        if (l == false || r == false)
        {
            return false;
        }
        
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