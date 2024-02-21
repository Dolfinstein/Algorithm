// 69. Sqrt(x)
 
#include <iostream>
 
using namespace std;
class Solution {
public:
    int mySqrt(int x) 
    {
        int count = 1;
        while(true)
        {
            if (count * count > x)
            {
                return count - 1;
            }
            else if (count * count == x)
            {
                return count;
            }
            count++;
        }
    }
};
int main()
{
    int x = 101;
    Solution abc;
    int ans = abc.mySqrt(x);
    cout << ans;
 
    return 0;
}