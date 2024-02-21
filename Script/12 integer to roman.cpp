// 12 integer to roman
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
 
int main()
{
    int num = 1994;
    unordered_map<int, char> hash = {
        {1, 'I'},
        {5, 'V'},
        {10, 'X'},
        {50, 'L'},
        {100, 'C'},
        {500, 'D'},
        {1000, 'M'}
    };
    vector<int> split;
    int division = 1000;
    while(division >= 1)
    {
        split.push_back(num / division);
        num = num - split[split.size() - 1] * division;
        division /= 10;
    }


    vector<char> ans;
    division = 1000;
    for (int idx = 0; idx < split.size(); idx++)
    {
        if (split[idx] != 4 and split[idx] != 9)
        {    
            if (split[idx] >= 5)
            {
                ans.push_back(hash[5 * division]);
                split[idx] -= 5 * division;
                for (int jdx = 0; jdx < split[idx]; jdx++)
                {
                    ans.push_back(hash[division]);
                }
            }
            else
            {
                for (int jdx = 0; jdx < split[idx]; jdx++)
                {
                    ans.push_back(hash[division]);
                }
            }
        }
        else if (split[idx] == 4)
        {
            ans.push_back(hash[division]);
            ans.push_back(hash[division * 5]);
        }
        else // split[idx] == 9
        {
            ans.push_back(hash[division]);
            ans.push_back(hash[division * 10]);
        }
        division /= 10;
    }
 
    
    for (int idx = 0; idx < ans.size(); idx++)
    {
        cout << ans[idx];
    }

 
    return 0;
}