// 98. Validate Binary Search Tree
// 此解法十分有意思，學到很多東西
// 1. 用lvr針對binary search tree做traverse 會是小到大的數字排序
// 2. lvr vlr lrv 三種traverse 都可以使用recurrence來做，而且十分簡單
// 3.  void inorderTraversal(TreeNode* root, vector<int>& ans)  這邊的ans有&，也就是要代入空的ans並且直接改動的時候就會這樣寫。
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
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
class Solution 
{
public:
    void inorderTraversal(TreeNode* root, vector<int>& ans) 
    {
        if (root != nullptr) 
        {
            // 遍历左子树
            inorderTraversal(root->left, ans);
            // 访问当前节点
            ans.push_back(root -> val);
            // 遍历右子树
            inorderTraversal(root->right, ans);
        }
    }
    bool isValidBST(TreeNode* root)
    {
        vector<int> ans;
        inorderTraversal(root, ans);
        for (int idx = 0; idx < ans.size() - 1; idx++)
        {
            if (ans[idx] >= ans[idx + 1])
            {
                return false;
            }
        }
        return true;
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
    cout << ans;
    // cout << ans.size();


 
    return 0;
}