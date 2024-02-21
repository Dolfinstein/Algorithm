#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> nums = [1,1,1,2,2,3];
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int time = 0;
    int ct = 0;
    int k = 0;
    int last = nums[0];
    // for (auto it = nums.begin(); it != )
    // int b = nums.begin();
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        if (time != 0)
        {
            if (last == *it)
            {
                ct = ct + 1;
                if (ct <= 2)
                {
                    nums[k] = nums[time];
                    k++;
                    time++;
                }
                else
                {
                    time++;
                }
            }
            else
            {
                ct = 1;
                nums[k] = nums[time];
                k++;
                time++;
            }
        }
        else
        {
            nums[k] = nums[time];
            time++;
            k++;
            ct++;
        }
        // cout << ct << " ";
        // cout << endl;
        last = *it;
    }

    for (int i = 0; i < nums.size(); i++) 
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << k;
    // cout << ;


    // for (auto it)
    



    return 0;
}



