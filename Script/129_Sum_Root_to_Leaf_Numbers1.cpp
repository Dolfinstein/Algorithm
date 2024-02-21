//129. Sum Root to Leaf Numbers
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <stack>
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
vector<int> sumNumbers(TreeNode* Node);
int main()
{
    TreeNode* root = new TreeNode(5);
    TreeNode* cur1 = root;
    cur1 -> left = new TreeNode(4);
    cur1 -> right = new TreeNode(8);
    TreeNode* cur2 = cur1 -> left;  
    TreeNode * cur3 = cur1 -> right;
    
    cur2 -> left = new TreeNode(1);
    // cur2 -> right = new TreeNode(4);
    
    
    
    cur3 -> left = new TreeNode(3);
    cur3 -> right = new TreeNode(4);
    cur3 -> right -> right = new TreeNode(1);
    
    TreeNode* cur5 = cur2 -> left;
    cur5 -> left = new TreeNode(7);
    cur5 -> right = new TreeNode(2);
    
    
    
    
    
    vector<int> ans = sumNumbers(root); 
    cout << ans[ans.size() - 1];
    
    
    
    

    return 0;
}



vector<int> sumNumbers(TreeNode* Node) 
{
    if (!Node)
    {
        vector<int> ans = {0};
        return ans;
    }
    if (!(Node -> left) && !(Node -> right))
    {
        vector<int> ans = {0, Node -> val};
        return ans;
    }
    int sum = 0;
    
    vector<int> lv = sumNumbers(Node -> left);
    vector<int> rv = sumNumbers(Node -> right);
    
    sum += lv[lv.size() - 1];
    sum += rv[rv.size() - 1];
    vector<int> ans;
    for (int idx = 0; idx < lv.size() - 1; idx++)
    {
        sum += Node -> val * pow(10, lv[idx] + 1);
        ans.push_back(lv[idx] + 1);
    }
    for (int idx = 0; idx < rv.size() - 1; idx++)
    {
        sum += Node -> val * pow(10, rv[idx] + 1);
        ans.push_back(rv[idx] + 1);
    }
    
    ans.push_back(sum);
    
    return ans;
    
}