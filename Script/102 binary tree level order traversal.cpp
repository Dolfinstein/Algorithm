// 102 binary tree level order traversal
 
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while(q.size() != 0)
        {
            queue<TreeNode*> q2;
            vector<int> ans_tmp;
            while(q.size() != 0)
            {
                cur = q.front();
                ans_tmp.push_back(cur -> val);
                q.pop();
                if (cur -> left)
                {
                    q2.push(cur -> left);
                }
                if (cur -> right)
                {
                    q2.push(cur -> right);    
                }
            }
            ans.push_back(ans_tmp);
            q = q2;
        }
        return ans;
    }
};
int main()
{
    TreeNode* root = new TreeNode(0);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> left =new TreeNode(3);
    root -> right -> left -> left = new TreeNode(4);
    root -> right ->left -> right = new TreeNode(5);
    root -> left -> left = new TreeNode(6);
    root -> left -> left -> left = new TreeNode(7);
    root -> left -> left -> left -> left = new TreeNode(8);
    Solution abc;

    vector<vector<int>> show = abc.levelOrder(root);
    cout << endl;
    for (int idx = 0; idx < show.size(); idx++)
    {
        vector<int> show2 = show[idx];
        for (int jdx = 0; jdx < show2.size(); jdx++)
        {
            cout << show2[jdx] << " ";    
        }
        cout << endl;
    }
 

    return 0;
}