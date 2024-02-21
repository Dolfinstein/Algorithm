// 3 longest substring without repeating characters;
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
 
using namespace std;
void display(const vector<int> &vec);
 
 
int main()
{
    string s = "bbbacbb";

    int max = 1;
    int left = 0;
    int right = 0;
    unordered_set<char> set = {s[left]};
    // right增加
    while(right != s.length() - 1)
    {
        right++;
        auto it = set.find(s[right]);
        if (it == set.end()) //不存在
        {
            set.insert(s[right]);
            if (right - left + 1 > max)
            {
                max = right - left + 1;
            }
        }
        else //存在
        {
            while(s[left] != s[right])
            {
                set.erase(s[left]);
                left++;
            }
            left++;
        }
    }
    cout << max;



    return 0;
}
void display(const vector<int> &vec)
{
    cout << endl;
    for (int idx = 0; idx < vec.size(); idx++)
    {
        cout << vec[idx] << ' ';
    }
    cout << endl;
}