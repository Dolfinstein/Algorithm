// 11 container with most water
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
void display(const vector<int> &vec);

 
 
 
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    vector<int> ans;
    int width = height.size() - 1;
    int left = 0;
    int right = height.size() - 1;
    int max = 0;
    while(left < right)
    {
        if (min(height[left], height[right]) * width > max)
        {
            max = min(height[left], height[right]) * width;
            ans = {};
            ans.push_back(left);
            ans.push_back(right);
        }
        if (height[left] <= height[right])
        {
            left++;
        }
        else // height[left]
        {
            right--;
        }
        width--;
    }
    cout << max;
    display(ans);

    return 0;
}
void display(const vector<int> &vec)
{
    cout << endl;
    for (int idx = 0; idx < vec.size(); idx++)
    {
        cout << vec[idx] << ' ';
    }
}