// 13 roman to integer
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
int main()
{
    unordered_map<char, int> hash = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    vector<char> c = {'M','C','M','X','C','I','V'};
    int tot = 0;
    int idx = 0;
    while(idx < c.size())
    {
        if(c[idx] == 'I')
        {
            if (c[idx + 1] == 'V')
            {
                tot += 4;
                idx += 2;
            }
            else if (c[idx + 1] == 'X')
            {
                tot += 9;
                idx += 2;
            }
            else
            {
                tot += hash[c[idx]];
                idx++;
            }
        }
        else if (c[idx] == 'X')
        {
            if (c[idx + 1] == 'L')
            {
                tot += 40;
                idx += 2;
            }
            else if (c[idx + 1] == 'C')
            {
                tot += 90;
                idx += 2;
            }
            else
            {
                tot += hash[c[idx]];
                idx++;
            }


        }
        else if (c[idx] == 'C')
        {
            if (c[idx + 1] == 'D')
            {
                tot += 400;
                idx += 2;
            }
            else if (c[idx + 1] == 'M')
            {
                tot += 900;
                idx += 2;
            }
            else
            {
                tot += hash[c[idx]];
                idx++;
            }
        }
        else
        {
            tot += hash[c[idx]];
            idx++;
        }
    }
    cout << tot;
 
    r