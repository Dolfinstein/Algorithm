//134 GAS STATION
// 思路很簡單 窮舉法 隨便一個開頭a 假設走到b就沒油了
// 首先一定代表gas(b) < cost(b) 那有可能從c出發 a<c<b 成功走過b嗎
// 答案是不可能 因為從a出發時走到c前剩餘的油一定大於等於0
// 從c出發時油會是0 因此從c出發到達b時油會比從a出發時更少
// 因此直接從b+1出發來測試即可
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
using namespace std;
void display(vector<int> vec);
 
 
 
int main()
{
    vector<int> gas = {2, 3, 4, 5};
    vector<int> cost = {3, 3, 3, 6};

    int tank;
    int attempt = 0;
    int ptr = 0;
    int walk;
    while(attempt < gas.size())
    {
        // 尋找起始點 如果cost比較大根本不可能
        if (gas[ptr % gas.size()] < cost[ptr % gas.size()])
        {
            ptr++;
            attempt++;
        }
        // 起始點合格
        else
        {
            walk = 0;
            while(tank >= 0 && walk < gas.size())
            {
                tank += gas[ptr % gas.size()];
                tank -= cost[ptr % gas.size()];
                ptr++;
                if (tank >= 0)
                {
                    walk++;
                }
                attempt++;
                if (walk == gas.size())
                {
                    cout << "yes";
                    exit(0);
                }
            }
        }
    }
    cout << "no";



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