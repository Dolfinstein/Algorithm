
//104. Maximum Depth of Binary Tree
// this is the bfs, using queue instead of two vector.
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
  
  
int bfs(TreeNode* root);
 
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
    
    
    int ans = bfs(root);
    cout << ans;
    
    
    
    
    

    return 0;
}

int bfs(TreeNode* node)
{
    int layers = 0;
    queue<TreeNode*> que = {};
    que.push(node);
    
    int size = 1;
    while(size > 0)
    {
        int size2 = size;
        for (int idx = 0; idx < size2; idx++)
        {
            TreeNode* target = que.front();
            que.pop();
            size--;
            if (target -> left)
            {
                que.push(target -> left);
                size++;
            }
            if(target -> right)
            {
                que.push(target -> right);
                size++;
            }
        }
        layers++;
    }
    
    return layers;
    
    
    
    
    
}