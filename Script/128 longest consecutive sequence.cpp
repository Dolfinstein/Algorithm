// 128 longest consecutive sequence
#include <iostream>
// #include <string>
#include <vector>
#include <unordered_map>
 
 
using namespace std;
 
int main()
{
    vector<int> nums = {-1, 100, 4, 200 , 1, 3, 2, 0};
    unordered_map<int, int> map;
    int longest = 0;
    int current;
    int target;
    for (int idx = 0; idx < nums.size(); idx++)
    {
        map[nums[idx]] = 0;
    }
    for (int idx = 0; idx < nums.size(); idx++)
    {
        if (map[nums[idx]] == 0)
        {
            map[nums[idx]] = 1;
            current = 1;
            target = nums[idx];
            while(true)
            {
                auto it = map.find(target - 1);
                if (it == map.end())
                {
                    break;
                }
                else
                {
                    target--;
                    map[target] = 1;
                    current++;
                }
            }
            target = nums[idx];
            while(true)
            {
                auto it = map.find(target + 1);
                if (it == map.end())
                {
                    break;
                }
                else
                {
                    target++;
                    map[target] = 1;
                    current++;
                }

            }
        }
        if (current > longest)
        {
            longest = current;
        }
    }

    cout << longest;
 
    return 0;
}