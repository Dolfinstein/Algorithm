// remove element
#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> vec);
 
int main()
{
    vector<int> num1 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int cur1 = 0;
    int cur2 = num1.size() - 1;
    while(cur1 < cur2)
    {
        while(num1[cur2] == val)
        {
            cur2--;
        }
        if (num1[cur1] == val)
        {
            num1[cur1] = num1[cur2];
            num1[cur2] = val;
            cur1++;
            cur2--;
        }
        else
        {
            cur1++;
        }
    }

 
    // int comp = num1[idx];
    display(num1);
    cout << cur2 + 1;
 
    return 0;
}
 
void display(vector<int> num1)
{
    for (int abc = 0; abc < num1.size(); abc++)
    {
        cout << num1[abc] << " ";
    }
    cout << endl;
}