//53. Maximum Subarray
// 用max改版
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int minValue = numeric_limits<int>::min();
        int sum = 0;
        int cur_max = minValue;
        int glo_max = minValue;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            sum += nums[idx];
            cur_max = max(cur_max, sum);
            // if (cur_max < sum)
            // {
            //     cur_max = sum;
            // }
            glo_max = max(glo_max, cur_max);
            // if (glo_max < cur_max)
            // {
            //     glo_max = cur_max;
            // }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return glo_max;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    nums = {-1};
    nums = {5,4,-1,7,8};
    nums = {-5,-3,-75};
    cout<<"Hello World";
    cout << endl;
    Solution abc;
    int ans = abc.maxSubArray(nums);
    cout << ans;
 
    return 0;
}