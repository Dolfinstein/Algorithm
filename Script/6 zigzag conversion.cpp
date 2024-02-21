// 6 zigzag conversion
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
 
 
 
int main()
{
    string s = "paypalishiring";
    int numRows = 4;


    int pivot = numRows + numRows - 2;
    int len = s.length();
    // s = s + 'a';
    string ans;
    int idx = 0;
    int mod = 0;
    while (idx * pivot + mod < len)
    {
        ans = ans + s[idx * pivot + mod];
        idx++;
    }

    for (mod = 1; mod < numRows - 1; mod++)
    {
        idx = 0;
        while(true)
        {
            if (idx * pivot + (pivot - mod) < len)
            {
                ans = ans + s[idx * pivot + mod];
                ans = ans + s[idx * pivot + (pivot - mod)];
                idx++;
            }
            else
            {
                if (idx * pivot + (mod) < len)
                {
                    ans = ans + s[idx * pivot + mod];
                    idx++;
                }
                break;
            }
        }
    }
    mod = numRows - 1;
    idx = 0;
    while (idx * pivot + mod < len)
    {
        ans = ans + s[idx * pivot + mod];
        idx++;
    }
    cout << ans;
 
 
 
    return 0;
}