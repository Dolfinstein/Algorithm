#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> nums = {-1,-100,3,99};
    int k = 3;
    int tmp;
    int size = nums.size() - 1;
    int rstart;
    int lstart = 0;
    int leftover = 0;
    int time = 0;
    rstart = size + 1 - k;
    while (true)
    {
        // time += 1;
        // if (time == 7)
        // {
        //     break;
        // }
        // if (lstart >= size + 1)
        // {
        //     break;
        // }
        // rstart = size + 1 - k;
        if (lstart + k <= rstart)
        {
            for (int idx = 0; idx < k; idx++)
            {
                tmp = nums[lstart + idx];
                nums[lstart + idx] = nums[rstart + idx];
                nums[rstart + idx] = tmp;
            }
            if (lstart + k == rstart)
            {
                break;
            }
            lstart += k;
        }
        else 
        {
            int k2 = k;
            k = rstart - lstart;
            k2 = k2 - k;
            for (int idx = 0; idx < k; idx++)
            {
                tmp = nums[lstart + idx];
                nums[lstart + idx] = nums[rstart + idx];
                nums[rstart + idx] = tmp;
            }
            lstart += k;
            k = k2;
            rstart = size + 1 - k;

        }
    }
    



    for (int idx = 0; idx < nums.size(); idx++)
    {
        cout << nums[idx] << " ";
    }


    return 0;
}