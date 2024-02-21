//130. Surrounded Regions
 
// 找到圈圈後 建立一個stack 接著把所有相連的點找出，並且加入stack，若最後沒有找到邊邊，stack的所有點都改成ｘ
// 若有找到邊邊，則把stack的東西加入ignore set
 
//速度超級慢！！！！！
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <stack>
 
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        unordered_set<string> ignore;
        for (int idx = 0; idx < board.size(); idx++)
        {
            for (int jdx = 0; jdx < board[0].size(); jdx++)
            {
                if (board[idx][jdx] == 'O')
                {
                    auto it = ignore.find(to_string(idx) + ',' + to_string(jdx));
                    if (it == ignore.end())
                    {

                        unordered_set<string> s;
                        stack<vector<int>> s2;
                        bool ans = findEdge(board, idx, jdx, s, s2);
                        if (ans == false)
                        {
                            while(s2.size() != 0)
                            {
                                vector<int> vec = s2.top();
                                ignore.insert(to_string(vec[0]) + ',' + to_string(vec[1]));
                                s2.pop();
                                board[vec[0]][vec[1]] = 'X';
                            }
                        }
                        else
                        {

 
                            while(s2.size() != 0)
                            {
                                vector<int> vec = s2.top();
                                ignore.insert(to_string(vec[0]) + ',' + to_string(vec[1]));
                                s2.pop();
                            }
                        }
                    }

                }
            }
        }
    }
    bool findEdge(vector<vector<char>>& board, int row, int col, unordered_set<string>& s, stack<vector<int>>& s2)
    {

        s.insert(to_string(row) + ',' + to_string(col));
        s2.push({row, col});

        bool ans1 = false;
        bool ans2 = false;
        bool ans3 = false;
        bool ans4 = false;
        bool ans5 = false;
        if (row - 1 >= 0 && board[row - 1][col] == 'O')
        {
            auto it = s.find(to_string(row - 1) + ',' + to_string(col));
            if (it == s.end())
            {
                ans1 = findEdge(board, row - 1, col, s, s2);
            }

        }
        if (col - 1 >= 0 && board[row][col - 1] == 'O')
        {
            auto it = s.find(to_string(row) + ',' + to_string(col - 1));
            if (it == s.end())
            {
                ans2 = findEdge(board, row, col - 1, s, s2);
            }

        }
        if (row + 1 < board.size() && board[row + 1][col] == 'O')
        {
            auto it = s.find(to_string(row + 1) + ',' + to_string(col));
            if (it == s.end())
            {
                ans3 = findEdge(board, row + 1, col, s, s2);
            }

        }
        if (col + 1 < board[0].size() && board[row][col + 1] == 'O')
        {
            auto it = s.find(to_string(row) + ',' + to_string(col + 1));
            if (it == s.end())
            {
                ans4 = findEdge(board, row, col + 1, s, s2);
            }

        }
        if (row - 1 < 0 || row + 1 >= board.size() || col - 1 < 0 || col + 1 >= board[0].size() )
        {
            ans5 = true;
        }
        return ans1 || ans2 || ans3 || ans4 || ans5;
    }
};
int main()
{
    vector<vector<char>> board = 
                           {{'O', 'O', 'O'},
                            {'X', 'O', 'X'},
                            {'O', 'X', 'O'}
                           };
    Solution abc;
    abc.solve(board);
    for (int idx = 0; idx < board.size(); idx++)
    {
        for (int jdx = 0; jdx < board[0].size(); jdx++)
        {
            cout << board[idx][jdx] << " ";
        }
        cout << endl;
    }

 
    return 0;
}