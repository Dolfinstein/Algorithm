//112. path sum
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
bool hasPathSum(TreeNode* root, int targetSum);
int main()
{
    TreeNode* root = new TreeNode(5);
    TreeNode* cur1 = root;
    cur1 -> left = new TreeNode(4);
    cur1 -> right = new TreeNode(8);
    TreeNode* cur2 = cur1 -> left;  
    TreeNode * cur3 = cur1 -> right;
    
    cur2 -> left = new TreeNode(11);
    // cur2 -> right = new TreeNode(4);
    
    
    
    cur3 -> left = new TreeNode(13);
    cur3 -> right = new TreeNode(4);
    cur3 -> right -> right = new TreeNode(1);
    
    TreeNode* cur5 = cur2 -> left;
    cur5 -> left = new TreeNode(7);
    cur5 -> right = new TreeNode(2);
    
    
    
    
    
    
    
    bool ans = hasPathSum(root, 19);
    cout << ans;
    
    
    
    

    return 0;
}



bool hasPathSum(TreeNode* root, int targetSum)
{
    vector<TreeNode*> stack;
    TreeNode* cur = root;
    stack.push_back(cur);
    int sum = root -> val;
    vector<TreeNode*> sub_stack;
    sub_stack.push_back(cur);
    
    while(stack.size() > 0)
    {
        
        if (!(cur -> left) && !(cur -> right))
            {
                if (sum == targetSum)
                {
                    return true;
                }
                else
                {
                    
                }
            }
        if (cur -> left)
        {
            cur = cur -> left;
            sum += cur -> val;
            stack.push_back(cur);
            sub_stack.push_back(cur);
            
        }
        else
        {
            while(stack.size() > 0)
            {
                cur = stack.back();
                stack.pop_back();
                int tmp = cur -> val;
                int idx;
                for (idx = 0; idx < sub_stack.size(); idx++)
                {
                    if (sub_stack[idx] == cur)
                    {
                        break;
                    }
                }
                for (int jdx = idx + 1; jdx < sub_stack.size(); jdx++)
                {
                    sum = sum - sub_stack[jdx] -> val;
                }
                int size = sub_stack.size();
                for (int jdx = idx + 1; jdx < size; jdx++)
                {
                    sub_stack.pop_back();
                }
                
                
                if (cur -> right)
                {
                    cur = cur -> right;
                    stack.push_back(cur);
                    sub_stack.push_back(cur);
                    sum = sum + cur -> val;
                    break;
                }
                
            }
            
            
        }
        
    }
    
    
    
    
    
    
    return false;
        
}