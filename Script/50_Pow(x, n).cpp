// 50. Pow(x, n)
#include <iostream>
 
using namespace std;
class Solution {
public:
    double myPow(double x, int n)
    {
        int now = 1;
        int last_iter = x;
        while(true)
        {
            if (now * 2 > n)
            {
                break;
            }
            last_iter = last_iter * last_iter;
            now *= 2;
        }
        n -= now;
        for (int idx = 0; idx < n; idx++)
        {
            last_iter *= x;
        }
        return last_iter;
    }
};
int main()
{
    double x = 2;
    int n = 6;
    Solution abc;
    double ans = abc.myPow(x, n);
    cout << ans;
 
    return 0;
}