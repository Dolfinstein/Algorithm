// 66. plus one
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int add = 1;
        int size = digits.size() - 1;
        for (int idx = size; idx >= 0; idx--)
        {
            digits[idx]++;
            if (digits[idx] == 10)
            {
                digits[idx] = 0;
            }
            else 
            {
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
int main()
{
    vector<int> digits = {9, 9, 9};
    Solution abc;
    vector<int> ans = abc.plusOne(digits);
    for (int idx = 0; idx < ans.size(); idx++)
    {
        cout << ans[idx] << " ";
    }
 
    return 0;
}