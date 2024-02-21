// 64. minimum path sum
// D.P.
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> dp;
    int minPathSum(vector<vector<int>>& grid)
    {
        int maxVal = numeric_limits<int>::max();    
        vector<int> tmpvec(grid[0].size(), maxVal);
        vector<int> vec;
        int sum = 0;
        for (int idx = 0; idx < grid[0].size(); idx++)
        {
            sum += grid[0][idx];
            vec.push_back(sum);
        }
        dp.push_back(vec);
        for (int idx = 1; idx < grid.size(); idx++)
        {
            dp.push_back(tmpvec);
        }
        sum = grid[0][0];
        for (int idx = 1; idx < grid.size(); idx++)
        {
            sum += grid[idx][0];
            dp[idx][0] = sum;
        }
        for (int idx = 1; idx < grid.size(); idx++)
        {
            for (int jdx = 1; jdx < grid[0].size(); jdx++)
            {
                loop(grid, idx, jdx);
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
    void loop(vector<vector<int>>& grid, int row, int col)
    {
        int ans = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
        dp[row][col] = ans;
    }
};
int main()
{
    // cout<<"Hello World";
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution abc;
    int ans = abc.minPathSum(grid);
    cout << ans;
    return 0;
}