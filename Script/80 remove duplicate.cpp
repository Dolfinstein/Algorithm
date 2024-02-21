//80 remove duplicate
#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> vec);
 
int main()
{
    vector<int> num1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6,7, 7, 8, 9, 10, 10, 11, 12, 13, 13, 13};
    int tmp;
    int cur1 = 0;
    int cur2 = 0;
    int count = 0;
    while(cur2 < num1.size())
    {
        tmp = num1[cur2];
        num1[cur1] = tmp;
        cur2++;
        cur1++;
        count++;
        while(num1[cur2] == tmp)
        {
            if(count < 2)
            {
                count++;
                num1[cur1] = tmp;
                cur2++;
                cur1++;
            }
            else
            {
                cur2++;
            }
        }
        count = 0;
    }

    display(num1);
    cout << cur1;
 
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