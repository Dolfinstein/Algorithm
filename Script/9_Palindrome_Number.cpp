// 9. Palindrome Number
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        int times = 10;
        vector<int> vec;
        int count = 0;
        while(true)
        {
            int last = x % times;
            vec.push_back(last);
            x -= (last);
            count++;
            if (!x)
            {
                break;
            }
            x = x / 10;
        }
        if ((count >> 1) & 1) // odd number
        {
            int size = vec.size() - 1;
            for (int idx = 0; idx < (count - 1) / 2; idx++)
            {
                // int size = vec.size() - 1;
                if (vec[0 + idx] != vec[size - idx])
                {
                    return false;
                }
            }
        }
        else
        {
            int size = vec.size() - 1;
            for (int idx = 0; idx < count / 2; idx++)
            {
                if (vec[0 + idx] != vec[size - idx])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution abc;
    int n = 123321;
    bool ans = abc.isPalindrome(n);
    cout << ans;
 
    return 0;
}