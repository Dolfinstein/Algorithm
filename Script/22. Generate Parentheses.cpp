//22. Generate Parentheses
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
 
class Solution
{
    public:
    vector<string> generateParenthesis(int n) 
    {
        string candidates;
        for (int idx = 0; idx < n; idx++)
        {
            candidates = candidates + "(" + ")";
        }
        perm(candidates);
        vector<string> ans;
        for (string it : final)
        {
            ans.push_back(it);
        }
        return ans;
    }
    unordered_set<string> final;
    unordered_set<string> final_erase;
    // vector<char> original;
    unordered_set<string> perm(string candidates)
    {
        string ans;
        string vec = candidates;
        int count = 0;
        loop(ans, candidates, count);
        for (string it : final)
        {
            int left = 0;
            // int right = 0;
            for (int idx = 0; idx < it.length(); idx++)
            {
                if (it[idx] == '(')
                {
                    left++;
                }
                else
                {
                    left--;
                }
                if (left < 0)
                {
                    final_erase.insert(it);
                    break;
                }
            }
        }
        for (string it : final_erase)
        {
            final.erase(it);
        }
        return final;
    }
    void loop(string ans, string vec, int count)
    {
        for (int idx = 0; idx < vec.length(); idx++)
        {
            if (vec[idx] == '0')
            {
                // vector<char> anstmp;
                // continue;
            }
            else
            {
                string anstmp = ans;
                string vectmp = vec;
                anstmp = anstmp + vec.substr(idx, 1);
                // anstmp.push_back(vec.substr(idx, 1));
                vectmp[idx] = '0';
                if (count != vec.length() - 1)
                {
                    loop(anstmp, vectmp, count + 1);
                }
                else
                {
                    final.insert(anstmp);
                }
            }

        }
    }

};
int main()
{
    // cout <<"hi";
    // vector<char> candidates{'a', 'b', 'b'};
    string candidates = "abb";
    Solution abc;
    vector<string> ans = abc.generateParenthesis(3);
    // ans = abc.vector<string> generateParenthesis(int n) 
    for (string it : ans)
    {
        for (int jdx = 0; jdx < it.length(); jdx++)
        {
            cout << it[jdx] << " ";
        }
        cout << endl;
    }
    cout << "there are " << ans.size() << " permutations";
    return 0;
}