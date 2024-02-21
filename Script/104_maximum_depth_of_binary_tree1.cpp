
//104. Maximum Depth of Binary Tree
// this is the bfs
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
    
    
    
    // vector<TreeNode*> vec = {};
    // vec.push_back(cur1);
    // cout << vec[0] -> val;
    

    return 0;
}

int bfs(TreeNode* node)
{
    int layers = 1;
    
    vector<TreeNode*> vec = {node};
    
    while(true)
    {
        vector<TreeNode*> vec2 = {};
        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            if ((*it) -> left)
            {
                vec2.push_back((*it) -> left);
            }
            if ((*it) -> right)
            {
                vec2.push_back((*it) -> right);
            }
        }
        if (vec2.size() == 0)
        {
            break;
        }
        layers++;
        vec = vec2;
    }
    return layers;
    
    
    
    
    
}