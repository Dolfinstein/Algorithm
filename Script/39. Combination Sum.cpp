// 39. Combination Sum
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> final;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> candidates_tmp = candidates;
        vector<int> ans;
        loop(candidates_tmp, target, ans);
        return final;
    }
    void loop(vector<int> candidates_tmp, int target, vector<int> ans)
    {
        int size = candidates_tmp.size();
        // if (size > 1)
        if (size == 1 )
        {
            size++;
        }
        // for (int idx = 0; idx < size - 1; idx++)
        // {   
            vector<int> ans_tmp = ans;
            int base = candidates_tmp[0];
            int count = 0;
            candidates_tmp.erase(candidates_tmp.begin());
            // cout << candidates_tmp.size() << " ";
            while(target - count * base >= 0)
            {
                cout << "base = " << base;
                cout << " count = " << count << " " << endl;
                if (count != 0)
                {
                    ans_tmp.push_back(base);
                }
                if (target - count * base == 0)
                {
                    final.push_back(ans_tmp);
                    for(int iii = 0; iii < ans_tmp.size(); iii++)
                    {
                        cout << ans_tmp[iii] << " ";
                    }
                    cout << endl;
                    break;
                }
                if (candidates_tmp.size() > 0)
                {
                    loop(candidates_tmp, target - count * base, ans_tmp);
                }
                count++;
            }
        // }
        // else
        // {   
        //     int base = candidates_tmp[0];
        //     int count = 1;
        //     while(target - count * base >= 0)
        //     {
        //         if (target - count * base == 0)
        //         {
        //             for (int idx = 0; idx < count; idx++)
        //             {
        //                 ans.push_back(base);
        //             }
        //             final.push_back(ans);
        //             break;
        //         }
        //         count++;
        //     }
        // }
    }
};
int main()
{
    vector<int> candidates = {1, 2, 3, 7};
    int target = 7;
    Solution abc;
    vector<vector<int>> ans = abc.combinationSum(candidates, target);
    // cout << endl;
    for (int idx = 0; idx < ans.size(); idx++)
    {
        cout << endl;
        for (int jdx = 0; jdx < ans[idx].size(); jdx++)
        {
            cout << ans[idx][jdx] << " ";
        }
    }
    // cout<<"Hello World";
    return 0;
}