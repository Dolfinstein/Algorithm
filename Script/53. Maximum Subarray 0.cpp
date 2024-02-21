//53. Maximum Subarray
#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int sum = 0;
        int cur_max = 0;
        int glo_max = 0;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            sum += nums[idx];
            if (cur_max < sum)
            {
                cur_max = sum;
            }
            if (glo_max < cur_max)
            {
                glo_max = cur_max;
            }
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
    cout<<"Hello World";
    cout << endl;
    Solution abc;
    int ans = abc.maxSubArray(nums);
    cout << ans;
 
    return 0;
}