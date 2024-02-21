// 49 group anagrams
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

void display(const vector<int> &vec);
void disp_mat(vector<vector<int>> &vec);
void disp_map(const unordered_map<char, char> & map);
int main()
{
vector<string> strs = {"tab", "tea", "tan", "ate", "nat", "bat"};
vector<unordered_map<char, int>> vec;
unordered_map<char, int> map;
vector<vector<string>> ans;

unordered_map<char, int> copy_map;
int need_new;

// 此for針對每個單字掃描
for (int large_tmp = 0; large_tmp < strs.size(); large_tmp++)
{
    unordered_map<char, int> new_map;
    need_new = 1;
    string target = strs[large_tmp];
    // 為第一個string做字典
    if (large_tmp == 0)
    {
        for (int idx = 0; idx < target.size(); idx++)
        {
            new_map[target[idx]]++;
        }
}
// 針對map中的字典
for (int idx = 0; idx < vec.size(); idx++)
    {
        int fail = 0;
        map = vec[idx];
        // 確認target是否是該map成員
        copy_map = map;
        int sym = 0;
        // 把字典中的字扣掉
        for (int jdx = 0; jdx < target.length(); jdx++)
            {
                //在字典中找字
                auto it = map.find(target[jdx]);
                if (it != map.end()) //若找的到字則減一
                    {
                        map[target[jdx]]--;
                    }
                else //找不到字的話
                {
                    fail = 1;
                    sym = 1;
                    if (idx != 0)
                    {
                        break;
                    }
                }
                if (idx == 0)
                {
                    new_map[target[jdx]]++;
                }
            }
        if (sym == 0)
        {
            for(auto it = map.begin(); it != map.end(); it++)
            {
                if (it -> second != 0)
                {
                    fail = 1;
                    break;
                }
            }
        }
        if (fail == 0)
        {
            ans[idx].push_back(target);
            need_new = 0;
            break;
        }

    }

if (need_new == 1)
{
    vec.push_back(new_map);
    vector<string> tmp = {};
    tmp.push_back(target);
    ans.push_back(tmp);
}
}
cout << ans.size() << endl;
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
void disp_mat(vector<vector<int>> &vec)
{
for (int idx = 0; idx < vec.size(); idx++)
{
for (int jdx = 0; jdx < vec[idx].size(); jdx++)
{
if (vec[idx][jdx] < 0)
{
cout << vec[idx][jdx] << ' ';
}
else
{
cout << ' ' << vec[idx][jdx] << ' ';
}
}
cout << endl;
}
}
void disp_map(const unordered_map<char, char> & map)
{
for (auto it = map.begin(); it != map.end(); it++)
{
cout << it -> first << ":" << it -> second << endl;
}
}