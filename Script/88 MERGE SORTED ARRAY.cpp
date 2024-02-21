// MERGE SORTED ARRAY
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<int> num1 = {1, 5, 7, 0, 0, 0};
    int m = 3;
    int n = 3;
    vector<int> num2 = {2, 4, 6};

    m = m - 1;
    n = n - 1;
    int idx = 0;
    int jdx = 0;
    int zdx = 0;
    // int tmp;
    while(jdx < (n + 1))
    {
        if (num1[m - idx] <= num2[n - jdx])
        {
            num1[m + n + 1 - zdx] = num2[n - jdx];
            jdx++;
            zdx++;
        }
        else
        {
            num1[m + n + 1 - zdx] = num1[m - idx];
            idx++;
            zdx++;
        }
    }
 
    // int comp = num1[idx];
    for (int abc = 0; abc < num1.size(); abc++)
    {
        cout << num1[abc] << " ";
    }
    cout << endl;
    cout<<"Hello World";
 
    return 0;
}