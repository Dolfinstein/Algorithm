// 34. Find First and Last Position of Element in Sorted Array
 
#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ans = {-1, -1};
        if (nums.size() == 0)
        {
            return ans;
        }
        if (nums[0] == target)
        {
            int count = 0;
            while(nums[count] == target)
            {
                count++;
                if (count + 0 >= nums.size())
                {
                    break;
                }
            }
            count--;
            ans[0] = 0;
            ans[1] = count;
            return ans;
        }
        else if (nums[nums.size() - 1] == target)
        {
            int last = nums.size() - 1;
            int count = 0;
            while(nums[last - count] == target)
            {
                count++;
                if (last - count < 0)
                {
                    break;
                }
            }
            count--;
            ans[1] = last;
            ans[0] = last - count;
            return ans;
        }
        int loc = loop(nums, target, 0, nums.size() - 1);
        if (loc == -1)
        {
            return ans;
        }
        int count = 0;
        while(nums[loc + count] == target)
        {
            count++;
        }
        count--;
        ans[1] = loc + count;
        count = 0;
        while(nums[loc - count] == target)
        {
            count++;
        }
        count--;
        ans[0] = loc - count;
        return ans;
    }

    int loop(vector<int>& nums, int target, int from, int to)
    {
        if (to - from <= 1)
        {
            if (nums[to] == target)
            {
                return to;
            }
            else if (nums[from] == target)
            {
                return from;
            }
            else
            {
                return -1;
            }
        }
        int mid = (from + to) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        int ans;
        if (nums[mid] < target)
        {
            ans = loop(nums, target, mid, to);
        }
        else
        {
            ans = loop(nums, target, from, mid);
        }
        return ans;
    }
};
int main()
{
    cout<<"Hello World";
    vector<int> nums = {1};
    int target = 1;
    Solution abc;
    vector<int> ans = abc.searchRange(nums, target);
    cout << endl;
    for (int idx = 0; idx < ans.size(); idx++)
    {
        cout << ans[idx] << " ";
    }
    return 0;
}