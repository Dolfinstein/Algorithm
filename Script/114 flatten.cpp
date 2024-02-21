// 114 flatten
// 我自己的想法中沒想到PRE可以用來記連接點
#include <iostream>
#include <vector>
using namespace std;
 
 
 
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        TreeNode* cur = root;
        while(cur -> left || cur -> right)
        {
            if (cur -> left)
            {
                // TreeNode* next = cur -> left;
                TreeNode* pre = cur -> left;
                while(pre -> right)
                {
                    pre = pre -> right;
                }
                TreeNode* tmp = cur -> right;
                cur -> right = cur -> left;
                cur -> left = nullptr;
                pre -> right = tmp;

            }
            cur = cur -> right;
        }

    }
};
 
TreeNode* make_tree(vector<int> vec);
int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -4, -4, -4, -4, 14};
    vec = {2, 1, 3, 0, 7, 9, 1, -4, -4, -4, 1, -4, -4, 5, -4};
    TreeNode* root = make_tree(vec);
    Solution abc;
    abc.flatten(root);
    // cout << root -> right->right-> right -> val;
    TreeNode* cur = root -> right -> right -> right -> right -> right -> right -> right -> right;
    cout << cur -> val;

    return 0;
}
TreeNode* make_tree(vector<int> vec)
{
    TreeNode* root = new TreeNode(vec[0]);

    int nod = 2;
    int cur = 1;
    TreeNode* cur_node;
    vector<TreeNode*> this_list = {root}; 
    vector<TreeNode*> next_list = {};
    while((cur - 1) + nod <= vec.size())
    {
        for (int idx = 0; idx < nod / 2; idx++)
        {
            // q.push_back(vec[cur]);
            cur_node = this_list[idx];
            if (cur_node -> val != -4)
            {
                if (vec[cur] != -4)
                {
                    cur_node -> left = new TreeNode(vec[cur]);
                    next_list.push_back(cur_node -> left);
                }
                else
                {
                    next_list.push_back(new TreeNode(-4));
                }
                cur++;
                if (vec[cur] != -4)
                {
                    cur_node -> right = new TreeNode(vec[cur]);
                    next_list.push_back(cur_node -> right);
                }
                else
                {
                    next_list.push_back(new TreeNode(-4));
                }
            }
            else
            {
                cur++;
            }
            cur++;
        }
        this_list = next_list;
        next_list = {};
        nod = nod * 2;
    }
    return root;
}