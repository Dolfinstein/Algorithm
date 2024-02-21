// 77. Combinations
 
#include <iostream>
#include <vector>
 
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> comb;
        vector<int> new_comb;
        loop(comb, n, 1, k, new_comb);
        return comb;
    }
    void loop(vector<vector<int>>& comb, int range, int from, int howmany_loop, vector<int> new_comb)
    {
        for (int idx = from; idx <= range - howmany_loop + 1; idx++)
        {
            vector<int> new_comb2 = new_comb;
            new_comb2.push_back(idx);
            if (howmany_loop - 1 > 0)
            {
                loop(comb, range, idx + 1, howmany_loop - 1, new_comb2);
            }
            else
            {
                comb.push_back(new_comb2);
            }
        }
    }
};
int main()
{
    int n = 5; 
    int k = 3;
    Solution abc;
    vector<vector<int>> ans = abc.combine(n, k);
    for (int idx = 0; idx < ans.size(); idx++)
    {
        for (int jdx = 0; jdx < ans[0].size(); jdx++)
        {
            cout << ans[idx][jdx] << ", ";
        }
        cout <<endl;
    }

 
    return 0;
}