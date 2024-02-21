// 74. Search a 2D Matrix
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int ans;
        // int sym = 0;
        for (int idx = 0; idx < matrix.size(); idx++)
        {
            if (target <= matrix[idx][matrix[0].size() - 1])
            {
                vector<int> nums = matrix[idx];
                ans = loop(nums, target, 0, nums.size() - 1);
                break;
            }
        }
        return ans;
    }
    bool loop(vector<int>& nums, int target, int from, int to)
    {
        if (to - from <= 1)
        {
            if (target == nums[from] || target == nums[to])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int loc;
        bool ans = false;
        if ((to - from + 1) % 2 == 1)
        {
            loc = (to + from) / 2;
        }
        else
        {
            loc = (to + from - 1) / 2;
        }
        if (nums[loc] == target)
        {
            return true;
        }
        else
        {
            if (nums[loc] < target)
            {
                ans = loop(nums, target, loc + 1, to);
            }
            else // nums[loc] > target
            {
                ans = loop(nums, target, from, loc - 1);
            }
            return ans;
        }
    }
};
 
int main()
{
    vector<vector<int>> matrix = {
                                {1,3,5,7},
                                {10,11,16,20},
                                {23,30,34,60}
                                };
    int target = 11;
    Solution abc;
    bool ans = abc.searchMatrix(matrix, target);
    cout << ans;
 
    return 0;
}