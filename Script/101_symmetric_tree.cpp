//101. symmetric tree
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
  
TreeNode* invertTree(TreeNode* root); 
bool isSymmetric(TreeNode* root);
bool mainsym(TreeNode* node1, TreeNode* node2);
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* cur1 = root;
    cur1 -> left = new TreeNode(2);
    cur1 -> right = new TreeNode(2);
    TreeNode* cur2 = cur1 -> left;
    TreeNode * cur3 = cur1 -> right;
    
    cur2 -> left = new TreeNode(3);
    cur2 -> right = new TreeNode(4);
    
    
    
    cur3 -> left = new TreeNode(3);
    cur3 -> right = new TreeNode(4);
    
    
    bool ans = isSymmetric(root);
    
    cout << ans;
    
    
    
    
    
    
    
    
    
    

    return 0;
}



bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        if (((root -> left) && !(root -> right)) || (!(root -> left) && (root -> right)))
        {
            return false;
        }
        if (!(root -> left) && !(root -> right))
        {
            return true;
        }
        
        
        
        TreeNode* root1 = root -> left;
        TreeNode* root2 = root -> right;
        if (root1 -> val != root2 -> val)
        {
            return false;
        }
        bool ans = mainsym(root1, root2);
        return ans;
        
    }



bool mainsym(TreeNode* node1, TreeNode* node2)
{
    if (!node1 && !node2)
    {
        return true;
    }
    
    
    
    if (((node1 -> left) && !(node2 -> right)) || (!(node1 -> left) && (node2 -> right)))
    {
        return false;
    }
    if (((node1 -> right) && !(node2 -> left)) || (!(node1 -> right) && (node2 -> left)))
    {
        return false;
    }
    
    bool b1 = mainsym(node1 -> left, node2 -> right);
    bool b2 = mainsym(node1 -> right, node2 -> left);
    
    
    if (b1 == false || b2 == false)
    {
        return false;
    }
    
    
    if (node1 -> val == node2 -> val)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}