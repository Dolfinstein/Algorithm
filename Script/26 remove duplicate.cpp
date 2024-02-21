//26 remove duplicate
#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> vec);
 
int main()
{
    vector<int> num1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int tmp;
    int cur1 = 0;
    int cur2 = 0;
    while(cur2 < num1.size())
    {
        tmp = num1[cur2];
        num1[cur1] = tmp;
        cur2++;
        cur1++;
        while(num1[cur2] == tmp)
        {
            cur2++;
        }
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