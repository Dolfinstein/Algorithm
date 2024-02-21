//104. Maximum Depth of Binary Tree
// this is the dfs
#include <iostream>
#include <vector>
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
  
  
int dfs(TreeNode* root);
 
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
    
    
    int ans = dfs(root);
    
    cout<<ans;

    return 0;
}

int dfs(TreeNode* node)
{
    if (!node)
    {
        return 0;
    }
    int l = bfs(node -> left);
    int r = bfs(node -> right);
    if (l >= r)
    {
        return l + 1;
    }
    else 
    {
        return r + 1;
    }
    
    
}