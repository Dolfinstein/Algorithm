// 17. Letter Combinations of a Phone Number
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<char, string> map;
    Solution() : map({{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}}) {}
    vector<string> letterCombinations(string digits)
    {
        vector<string> cur_comb;
        string tar = map[digits[0]];
        for (int idx = 0; idx < tar.length(); idx++)
        {
            string tmp = tar.substr(idx, 1);
            cur_comb.push_back(tmp);
        }
        loop(digits, 1, cur_comb);
        return cur_comb;

    }
    void loop(string digits, int now, vector<string>& cur_comb)
    {
        vector<string> new_comb;
        string tar2 = map[digits[now]];
        for (int idx = 0; idx < cur_comb.size(); idx++)
        {
            string tar1 = cur_comb[idx];
            for (int jdx = 0; jdx < tar2.length(); jdx++)
            {
                new_comb.push_back(tar1 + tar2.substr(jdx, 1));
            }
        }
        cur_comb = new_comb;
        if (now + 1 < digits.length())
        {
            loop(digits, now + 1, cur_comb);
        }
    }
};
int main()
{
    Solution abc;
    string digits = "29";
    vector<string> ans = abc.letterCombinations(digits);
    for (int idx = 0; idx < ans.size(); idx++)
    {
        cout << ans[idx] << " ";
    }

    return 0;
}