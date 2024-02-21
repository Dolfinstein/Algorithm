//53. Maximum Subarray
// D.P.
// 仔細看 
//glo_max = max(glo_max, ans); 比
// if (glo_max < ans)
// {
//     glo_max = ans;
// }
// 還要快
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int minValue = numeric_limits<int>::min();
        int prev = minValue;
        int glo_max = minValue;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            int ans;
            if (idx == 0)
            {
                ans = nums[idx];
            }
            else
            {
                ans = max({prev + nums[idx], nums[idx]});
            }
            glo_max = max(glo_max, ans);
            // if (glo_max < ans)
            // {
            //     glo_max = ans;
            // }
            prev = ans;
        }
        return glo_max;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // nums = {-1};
    // nums = {5,4,-1,7,8};
    // nums = {-5,-3,-75};
    cout<<"Hello World";
    cout << endl;
    Solution abc;
    int ans = abc.maxSubArray(nums);
    cout << ans;
 
    return 0;
}