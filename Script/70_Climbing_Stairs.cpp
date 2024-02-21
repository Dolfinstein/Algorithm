// 70. Climbing Stairs
// using d.p.
// the point is to consider the last number
// if the last number is 1, then the number of solution is equal to the case of n - 1
// if the last number is 2, then the number of solution is equal to the case of n - 2 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int ans = climbStairs(n - 1) + climbStairs(n - 2);
        return ans;
    }
};
int main()
{
    int n = 4;
    Solution abc;
    int ans = abc.climbStairs(n);
    cout << ans;
 
    return 0;
}