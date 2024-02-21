// 14 longest common prefix
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main()
{
    vector<string> vec;
    vec.push_back("flow");
    vec.push_back("flower");
    vec.push_back("flowht");
    vector<char> ans;
    int idx = 0;
    while(true)
    {
        // int idx = 0
        char pivot = vec[0][idx];
        for(int jdx = 1; jdx < vec.size(); jdx++)
        {
            if (vec[jdx][idx] != pivot)
            {
                for(int zdx = 0; zdx < ans.size(); zdx++)
                {
                    cout << ans[zdx];
                }
                exit(0);
            }
        }
        ans.push_back(pivot);
        idx++;
    }



 
    return 0;
}