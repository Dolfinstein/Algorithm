// 108. convert sortyed array to binary search tree
// 使用二分法
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode* root = new TreeNode;
        queue<int> q;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            q.push(nums[idx]);
        }
        loop(q, root);
        return root;
    }
    void loop(queue<int> q, TreeNode* root) // determine the val of the root, and put the right queue to left and right.
    {
        int size = q.size(); // q for the right, 
        if (size == 2)
        {
            root -> val = q.front();
            q.pop();
            root -> right = new TreeNode(q.front());
            return;
        }
        else if (size == 1)
        {
            root -> val = q.front();
            return;
        }
        queue<int> q2; // q2 for the left
        if (size % 2 == 0)
        {
            for(int idx = 0; idx < (size / 2) - 1; idx++)
            {
                q2.push(q.front());
                q.pop();
            }
            root -> val = q.front();
            q.pop();
            root -> left = new TreeNode;
            root -> right = new TreeNode;
            if (q2.size())
            {
                loop(q2, root -> left);
            }
            if (q.size())
            {
                loop(q, root -> right);
            }
        }
        else
        {
            for (int idx = 0; idx < (size - 1) / 2; idx++)
            {
                q2.push(q.front());
                q.pop();
            }
            root -> val = q.front();
            q.pop();
            root -> left = new TreeNode;
            root -> right = new TreeNode;
            if (q2.size())
            {
                loop(q2, root -> left);
            }
            if (q.size())
            {
                loop(q, root -> right);
            }
        }
    }
};
int main()
{
    Solution abc;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    TreeNode* root = abc.sortedArrayToBST(nums);
    TreeNode* cur = root;
    cur = cur  -> right -> right -> right;
    cout << cur -> val;

    return 0;
}