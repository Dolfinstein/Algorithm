// 35. Search Insert Position
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int ans = loop(nums, target, 0, nums.size() - 1);
        return ans;
    }
    int loop(vector<int>& nums, int target, int from, int to)
    {
        if (to - from == 1)
        {
            if (target <= nums[from])
            {
                return from;
            }
            else if (nums[from] < target && target <= nums[to])
            {
                return to;
            }
            else
            {
                return to + 1;
            }
        }
        else if (to == from)
        {
            if (nums[to] < target)
            {
                return to + 1;
            }
            else 
            {
                return to;
            }
        }
        int loc;
        int ans = 100;
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
            return loc;
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
    // cout<<"Hello World";
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    Solution abc;
    int ans = abc.searchInsert(nums,  target);
    cout << ans;

    return 0;
}