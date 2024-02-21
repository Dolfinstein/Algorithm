// 36 valid sudoku
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
 
using namespace std;
void display(const vector<int> &vec);
 
 
int main()
{
    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '3', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    unordered_set<char> c1;
    unordered_set<char> c2;
    unordered_set<char> c3;
    unordered_set<char> c4;
    unordered_set<char> c5;
    unordered_set<char> c6;
    unordered_set<char> c7;
    unordered_set<char> c8;
    unordered_set<char> c9;
    vector<unordered_set<char>> c = {c1, c2, c3, 
        c4, c5, c6, c7, c8, c9
    };
    unordered_set<char> r1;
    unordered_set<char> r2;
    unordered_set<char> r3;
    unordered_set<char> r4;
    unordered_set<char> r5;
    unordered_set<char> r6;
    unordered_set<char> r7;
    unordered_set<char> r8;
    unordered_set<char> r9;
    vector<unordered_set<char>> r = {r1, r2, r3, 
        r4, r5, r6, r7, r8, r9};
    unordered_set<char> b1;
    unordered_set<char> b2;
    unordered_set<char> b3;
    unordered_set<char> b4;
    unordered_set<char> b5;
    unordered_set<char> b6;
    unordered_set<char> b7;
    unordered_set<char> b8;
    unordered_set<char> b9;
    vector<unordered_set<char>> b = {b1, b2, b3, 
        b4, b5, b6, b7, b8, b9
    };

    for (int idx = 0; idx < 9; idx++)
    {
        for (int jdx = 0; jdx < 9; jdx++)
        {
            if (board[idx][jdx] != '.')
            {
                auto it = r[idx].find(board[idx][jdx]);
                if (it != r[idx].end())
                {
                    cout << "false1";
                    exit(0);
                }
                auto itt = c[jdx].find(board[idx][jdx]);
                if (itt != c[jdx].end())
                {
                    cout << "false2";
                    exit(0);
                }
                auto ittt = b[(idx / 3)* 3 + (jdx / 3)].find(board[idx][jdx]);
                if (ittt != b[(idx / 3) * 3 + (jdx / 3)].end())
                {
                    cout << idx << " " << jdx;
                    cout << "false3";
                    exit(0);
                }
                r[idx].insert(board[idx][jdx]);
                c[jdx].insert(board[idx][jdx]);
                b[(idx / 3) * 3 + (jdx / 3)].insert(board[idx][jdx]);

            }
        }
    }
    cout << "true";



    return 0;
}
void display(const vector<int> &vec)
{
    cout << endl;
    for (int idx = 0; idx < vec.size(); idx++)
    {
        cout << vec[idx] << ' ';
    }
    cout << endl;
}// 36 valid sudoku
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
 
using namespace std;
void display(const vector<int> &vec);
 
 
int main()
{
    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '3', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    unordered_set<char> c1;
    unordered_set<char> c2;
    unordered_set<char> c3;
    unordered_set<char> c4;
    unordered_set<char> c5;
    unordered_set<char> c6;
    unordered_set<char> c7;
    unordered_set<char> c8;
    unordered_set<char> c9;
    vector<unordered_set<char>> c = {c1, c2, c3, 
        c4, c5, c6, c7, c8, c9
    };
    unordered_set<char> r1;
    unordered_set<char> r2;
    unordered_set<char> r3;
    unordered_set<char> r4;
    unordered_set<char> r5;
    unordered_set<char> r6;
    unordered_set<char> r7;
    unordered_set<char> r8;
    unordered_set<char> r9;
    vector<unordered_set<char>> r = {r1, r2, r3, 
        r4, r5, r6, r7, r8, r9};
    unordered_set<char> b1;
    unordered_set<char> b2;
    unordered_set<char> b3;
    unordered_set<char> b4;
    unordered_set<char> b5;
    unordered_set<char> b6;
    unordered_set<char> b7;
    unordered_set<char> b8;
    unordered_set<char> b9;
    vector<unordered_set<char>> b = {b1, b2, b3, 
        b4, b5, b6, b7, b8, b9
    };

    for (int idx = 0; idx < 9; idx++)
    {
        for (int jdx = 0; jdx < 9; jdx++)
        {
            if (board[idx][jdx] != '.')
            {
                auto it = r[idx].find(board[idx][jdx]);
                if (it != r[idx].end())
                {
                    cout << "false1";
                    exit(0);
                }
                auto itt = c[jdx].find(board[idx][jdx]);
                if (itt != c[jdx].end())
                {
                    cout << "false2";
                    exit(0);
                }
                auto ittt = b[(idx / 3)* 3 + (jdx / 3)].find(board[idx][jdx]);
                if (ittt != b[(idx / 3) * 3 + (jdx / 3)].end())
                {
                    cout << idx << " " << jdx;
                    cout << "false3";
                    exit(0);
                }
                r[idx].insert(board[idx][jdx]);
                c[jdx].insert(board[idx][jdx]);
                b[(idx / 3) * 3 + (jdx / 3)].insert(board[idx][jdx]);

            }
        }
    }
    cout << "true";



    return 0;
}
void display(const vector<int> &vec)
{
    cout << endl;
    for (int idx = 0; idx < vec.size(); idx++)
    {
        cout << vec[idx] << ' ';
    }
    cout << endl;
}