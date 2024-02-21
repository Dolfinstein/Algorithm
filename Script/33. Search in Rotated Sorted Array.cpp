// 33. Search in Rotated Sorted Array
// 重點在找規律
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int ans;
        if (nums[0] < nums[nums.size() - 1])
        {
            ans = norm(nums, target, 0, nums.size() - 1);
        }
        else
        {
            ans = rotate(nums, target, 0, nums.size() - 1);
        }
        return ans;
    }
    int rotate(vector<int>& nums, int target, int from, int to) // 確定是rotate才做
    {
        if (to - from <= 1)
        {
            if (target == nums[to])
            {
                return to;
            }
            else if (target == nums[from])
            {
                return from;
            }
            else
            {
                return -1;
            }
        }
        int mid = (from + to) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        int ans;
        if (nums[mid] > nums[from])
        {
            if (target > nums[mid])
            {
                if (nums[mid] < nums[to]) //往右
                {
                    ans = norm(nums, target, mid, to);
                }
                else
                {
                    ans = rotate(nums, target, mid, to);
                }
            }
            else
            {
                if (target == nums[to])
                {
                    return to;
                }
                else if (target < nums[to])
                {
                    if (nums[mid] < nums[to]) //往右
                    {
                        ans = norm(nums, target, mid, to);
                    }
                    else
                    {
                        ans = rotate(nums, target, mid, to);
                    }
                }
                else
                {
                    if (nums[from] < nums[mid]) // 往左
                    {
                        ans = norm(nums, target, from, mid);
                    }
                    else
                    {
                        ans = rotate(nums, target, from, mid);
                    }
                }
            }
        }
        else
        {
            if (target < nums[mid])
            {
                if (nums[from] < nums[mid]) // 往左
                {
                    ans = norm(nums, target, from, mid);
                }
                else
                {
                    ans = rotate(nums, target, from, mid);
                }
            }
            else
            {
                if (target == nums[to])
                {
                    return to;
                }
                else if (target < nums[to])
                {
                    if (nums[mid] < nums[to]) //往右
                    {
                        ans = norm(nums, target, mid, to);
                    }
                    else
                    {
                        ans = rotate(nums, target, mid, to);
                    }
                }
                else
                {
                    if (nums[from] < nums[mid]) // 往左
                    {
                        ans = norm(nums, target, from, mid);
                    }
                    else
                    {
                        ans = rotate(nums, target, from, mid);
                    }
                }
            }
        }
        return ans;
    }

    int norm(vector<int>& nums, int target, int from, int to) // 一般的binery search
    {
        if (to - from <= 1)
        {
            if (target == nums[to])
            {
                return to;
            }
            else if (target == nums[from])
            {
                return from;
            }
            else
            {
                return -1;
            }
        }
        int mid = (from + to) / 2;
        int ans;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (target > nums[mid])
        {
            ans = norm(nums, target, mid, to);
        }
        else
        {
            ans = norm(nums, target, from, mid);
        }
        return ans;
    }
};
int main()
{
    cout<<"Hello World";
    vector<int> nums = {3, 5, 1};
    Solution abc;
    int ans = abc.search(nums, 1);
    cout << endl << ans;
    return 0;
}