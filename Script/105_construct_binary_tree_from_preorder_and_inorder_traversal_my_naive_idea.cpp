// 105 Construct Binary Tree from Preorder and Inorder Traversal
// my naive ideas
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
 
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.size() == 1)
        {
            TreeNode* root = new TreeNode(preorder[0]);
            return root;
        }
        unordered_map<int, int> inmap;
        for (int idx = 0; idx < inorder.size(); idx++)
        {
            inmap[inorder[idx]] = idx;
        }
        
        unordered_map<int, int> premap;
        for (int idx = 0; idx < preorder.size(); idx++)
        {
            premap[preorder[idx]] = idx;
        }
        
        int target = preorder[0];
        
        int left_start = 0;
        int left_end;
        if (inmap[target] - 1 >= 0)
        {
            left_end = inmap[target] - 1;
        }
        else
        {
            left_start = 3333;
            left_end = 3333;
        }
        int right_start;
        if (inmap[target] + 1 < preorder.size())
        {
            right_start = inmap[target] + 1;
        }
        else
        {
            right_start = 3333;
        }
        int right_end = preorder.size() - 1;
        
        TreeNode* root = new TreeNode(target);
        
        loop(root, premap, inmap, left_start, left_end, right_start, right_end, inorder, preorder);
        return root;
        
    }
    void loop(TreeNode* cur, unordered_map<int, int> premap, unordered_map<int, int> inmap, int left_start, int left_end, int right_start, int right_end, vector<int> inorder, vector<int> preorder)
    {
        // deal with left
        if (left_start != 3333)
        {
            if (left_start == left_end)
            {
                int left_target_value = inorder[left_start];
                {
                    cur -> left = new TreeNode(left_target_value);
                }
            }
            else
            {
                int left_min = 3333;
                for (int idx = left_start; idx <= left_end; idx++)
                {
                    if (premap[inorder[idx]] < left_min)
                    {
                        left_min = premap[inorder[idx]];
                    }
                }
                int left_target_value = preorder[left_min];
                cur -> left = new TreeNode(left_target_value);
                int left_mid = inmap[left_target_value];
                TreeNode* cur_left = cur -> left;
                if (left_mid == left_start)
                {
                    
                    loop(cur_left, premap, inmap, 3333, 3333, left_mid + 1, left_end, inorder, preorder);
                }
                else if (left_mid == left_end)
                {
                    
                    loop(cur_left, premap, inmap, left_start, left_mid - 1, 3333, 3333, inorder, preorder);
                }
                else
                {
                    
                    loop(cur_left, premap, inmap, left_start, left_mid - 1, left_mid + 1, left_end, inorder, preorder);
                }
            }
        }
        
        // deal with right
        if (right_start != 3333)
        {
            
            if (right_start == right_end)
            {
                int right_target_value = inorder[right_start];
                {
                    cur -> right = new TreeNode(right_target_value);
                }
            }
            else
            {
                int right_min = 3333;
                for (int idx = right_start; idx <= right_end; idx++)
                {
                    if (premap[inorder[idx]] < right_min)
                    {
                        right_min = premap[inorder[idx]];
                    }
                }
                int right_target_value = preorder[right_min];
                cur -> right = new TreeNode(right_target_value);
                int right_mid = inmap[right_target_value];
                if (right_mid == right_start)
                {
                    TreeNode* cur_right = cur -> right;
                    loop(cur_right, premap, inmap, 3333, 3333, right_mid + 1, right_end, inorder, preorder);
                }
                else if (right_mid == right_end)
                {
                    TreeNode* cur_right = cur -> right;
                    loop(cur_right, premap, inmap, right_start, right_mid - 1, 3333, 3333, inorder, preorder);
                }
                else
                {
                    TreeNode* cur_right = cur -> right;
                    loop(cur_right, premap, inmap, right_start, right_mid - 1, right_mid + 1, right_end, inorder, preorder);
                }
            }
        }
    }
};
int main()
{
    
    vector<int> preorder = {1, 2}; // vlr
    vector<int> inorder= {2, 1}; // lvr
    
    Solution abc;
    TreeNode* root = abc.buildTree(preorder, inorder);
    cout << root  -> left -> val;

    return 0;
}