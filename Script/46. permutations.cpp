//46. permutations
// 有大量set計算，是否可以再優化?
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> comb;
        unordered_set<int> set;
        vector<int> combtmp;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            set.insert(nums[idx]);
        }
        loop(set, comb, combtmp);
        return comb;
    }
    void loop(unordered_set<int> set, vector<vector<int>> & comb, vector<int> combtmp)
    {
        for (int idx : set)
        {
            unordered_set<int> settmp = set;
            settmp.erase(idx);
            vector<int> combtmp2 = combtmp;
            combtmp2.push_back(idx);
            if (settmp.size() == 0)
            {
                comb.push_back(combtmp2);
            }
            else
            {
                loop(settmp, comb, combtmp2);
            }
        }
    }
};
 
int main()
{
    vector<int> nums = {3, 2, 1, 0};
    Solution abc;
    vector<vector<int>> ans = abc.permute(nums);
    for (int idx = 0; idx < ans.size(); idx++)
    {
        for (int jdx = 0; jdx < ans[0].size(); jdx++)
        {
            cout << ans[idx][jdx] << ", ";
        }
        cout <<endl;
    }
    cout << ans.size();

 
    return 0;
}