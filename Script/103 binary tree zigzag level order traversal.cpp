// 103 binary tree zigzag level order traversal
 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        stack<TreeNode*> s;
        int sym = 1;
        TreeNode* cur;
        s.push(root);
        while(s.size() != 0)
        {
            stack<TreeNode*> s2;
            vector<int> ans_tmp;
            while(s.size() != 0)
            {
                cur = s.top();
                ans_tmp.push_back(cur -> val);
                s.pop();
                if (sym == 1)
                {
                    if (cur -> left)
                    {
                        s2.push(cur -> left);
                    }
                    if (cur -> right)
                    {
                        s2.push(cur -> right);
                    }
                }
                else if (sym == -1)
                {
                    if (cur -> right)
                    {
                        s2.push(cur -> right);
                    }
                    if (cur -> left)
                    {
                        s2.push(cur -> left);
                    }
                }
            }
            sym = sym * (-1);
            s = s2;
            ans.push_back(ans_tmp);
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

    vector<vector<int>> show = abc.zigzagLevelOrder(root);
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