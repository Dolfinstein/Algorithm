// 63. Unique Paths II
// my naive D.P. solution
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dp1; //記錄到每一格有幾種方式
    vector<int> dp2;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        vector<int> zero(obstacleGrid[0].size(), 0);
        dp1 = zero;
        dp1[0] = 1;
        int sym = 0;
        // int sum = 0;
        for (int idx = 0; idx < obstacleGrid[0].size(); idx++)
        {
            if (obstacleGrid[0][idx] == 1)
            {
                // dp1[idx] = 0;
                sym = 1;
            }
            else
            {
                if (!sym)
                {
                    // sum += obstacleGrid[0][idx];
                    dp1[idx] = 1;
                }
            }
        }
        dp2 = zero;
        for (int idx = 1; idx < obstacleGrid.size(); idx++)
        {
            loop(obstacleGrid, idx);
        }
        int ans = dp1[dp1.size() - 1];
        return ans;
    }
    void loop(vector<vector<int>>& obstacleGrid, int row)
    {
        vector<int> zero(obstacleGrid[0].size(), 0);
        for (int idx = 0; idx < obstacleGrid[0].size(); idx++)
        {
            if (obstacleGrid[row][idx] == 0)
            {
                if (!idx)
                {
                    dp2[idx] = dp1[idx];
                }
                else
                {
                    dp2[idx] = dp1[idx] + dp2[idx - 1];
                }
            }
        }
        dp1 = dp2;
        dp2 = zero;
    }
};
int main()
{
    // cout<<"Hello World";
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,0,0},{0,0,0}};
    Solution abc;
    int ans = abc.uniquePathsWithObstacles(obstacleGrid);
    cout << ans;
 
    return 0;
}