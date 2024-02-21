// 98. Validate Binary Search Tree
// recurrence
#include <iostream>
#include <cmath>
#include <vector>
// #include <algorithm>
using namespace std;
 
// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        vector<int> vec = minmax(root);
        if (vec[2] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    vector<int> minmax(TreeNode* root)
    {
        vector<int> ans = {0, 0, 1};
        if (!root -> left && !root -> right)
        {
            ans[0] = (root -> val);
            ans[1] = (root -> val);
            // ans[2] = 1;
            return ans;
        }

        vector<int> leftv;
        vector<int> rightv;
        if (root -> left)
        {
            leftv = minmax(root -> left);
            if (leftv[2] == 0 || leftv[1] >= root -> val)
            {
                ans[2] = 0;
                // ans.push_back(0);
                // ans.push_back(0);
                // ans.push_back(0);
                return ans;
            }
        }
        if (root -> right)
        {
            rightv = minmax(root -> right);
            if (rightv[2] == 0 || rightv[0] <= root -> val)
            {
                ans[2] = 0;
                // ans.push_back(0);
                // ans.push_back(0);
                // ans.push_back(0);
                return ans;
            }
        }
        if (leftv.size() == 0 && rightv.size() != 0)
        {
            ans[0] = root -> val;
            ans[1] = rightv[1];
            // ans.push_back(root -> val);
            // ans.push_back(rightv[1]);
        }
        else if (leftv.size() != 0 && rightv.size() == 0)
        {
            ans[0] = leftv[0];
            ans[1] = root -> val;
            // ans.push_back(leftv[0]);
            // ans.push_back(root -> val);
        }
        else if (leftv.size() != 0 && rightv.size() != 0)
        {
            // ans.push_back(min(root -> val, leftv[0], rightv[0]));
            // ans.push_back(leftv[0]);
            ans[0] = leftv[0];
            // ans.push_back(max(root -> val, leftv[1], rightv[1]));
            // ans.push_back(rightv[1]);
            ans[1] = rightv[1];
        }
        // ans.push_back(1);
        return ans;
    }
};
 
int main()
{
    TreeNode* root = new TreeNode(4);
    TreeNode* cur = root;
    cur -> left = new TreeNode(2);
    cur -> right = new TreeNode(5);
    cur = cur -> left;
    cur -> left = new TreeNode(1);
    cur -> right = new TreeNode(3);
    cur = root -> right;
    // cur -> left = new TreeNode(6);
    cur -> right = new TreeNode(10);
    cur = root -> right -> right;
    cur -> left = new TreeNode(7);
    cur = root -> right -> right -> left;
    cur -> left = new TreeNode(6);
    Solution abc;
    bool ans = abc.isValidBST(root);
    cout << endl;
    cout << ans;

 
    return 0;
}