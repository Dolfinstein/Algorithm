// 120. Triangle
// d.p.
// just like 官方解答
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    vector<int> save;
    vector<int> save2;
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> tmpvec(triangle.size(), 0);
        save = tmpvec;
        save2 = tmpvec;
        save[0] = triangle[0][0];
        for (int idx = 1; idx < triangle.size(); idx++)
        {
            loop(triangle, idx);
        }
        int mini = numeric_limits<int>::max();
 
        for (int idx = 0; idx < save.size(); idx++)
        {
            mini = min(mini, save[idx]);
        }

        return mini;
    }
    void loop(vector<vector<int>>& triangle, int to)
    {
        vector<int> tmpvec(triangle.size(), 0);
        for (int idx = 0; idx <= to; idx++)
        {
            if (idx == 0)
            {
                save2[idx] = save[idx] + triangle[to][idx];
            }
            else if (idx == to)
            {
                save2[idx] = save[idx - 1] + triangle[to][idx];
            }
            else
            {
                save2[idx] = min(save[idx - 1] , save[idx]) + triangle[to][idx];
            }
        }
        save = save2;
        save2 = tmpvec;
        return;
    }
};
int main()
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution abc;
    int ans = abc.minimumTotal(triangle);
    cout << ans;
    return 0;
}