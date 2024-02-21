// 67. Add Binary
// 傳統方式
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
    int add = 0; 
    string addBinary(string a, string b) 
    {
        int lena = a.length();
        int lenb = b.length();
        int counta = 0;
        int countb = 0;
        string ans;
        while(counta < lena || countb < lenb)
        {
            counta++;
            countb++;
            char tara;
            char tarb;
            if (counta <= lena)
            {
                tara = a[lena - counta];
            }
            else
            {
                tara = '0';
            }
            if (countb <= lenb)
            {
                tarb = b[lenb - countb];
            }
            else
            {
                tarb = '0';
            }

            if (tara == '1' && tarb == '1')
            {
                if (add == 0)
                {
                    ans = "0" + ans;
                    add = 1;
                }
                else
                {
                    ans = "1" + ans;
                }
            }
            else if (tara == '1' || tarb == '1')
            {
                if (add == 0)
                {
                    ans = "1" + ans;
                }
                else
                {
                    ans = "0" + ans;
                }
            }
            else
            {
                if (add == 0)
                {
                    ans = "0" + ans;
                }
                else
                {
                    ans = "1" + ans;
                    add = 0;
                }
            }
        }
        if (add == 1)
        {
            ans = '1' + ans;
        }
        return ans;
    }
};
int main()
{
    string a = "1010";
    string b = "1011";
    Solution abc;
    string c = abc.addBinary(a, b);
    cout << c;
 
    return 0;
}