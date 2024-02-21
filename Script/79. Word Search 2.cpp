// 79. Word Search
// second try, put board and word into global variables
// still can't pass the test!!
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool final_ans = false;
    vector<vector<char>> board;
    string word;
    bool exist(vector<vector<char>>& board2, string word2) {
        word = word2;
        int index = 0;
        board = board2;
        for (int idx = 0; idx < board.size(); idx++)
        {
            for (int jdx = 0; jdx < board[0].size(); jdx++)
            {
                vector<vector<int>> ignore(board.size(), vector<int>(board[0].size(), 0));
                loop(index, idx, jdx, ignore);
            }
        }
        return final_ans;
    }
    void loop(int index, int row, int col, vector<vector<int>> ignore)
    {
        if (final_ans == true)
        {
            return;
        }
        // cout << col << " " << row << endl;
        if (ignore[row][col] == 1)
        {
            return;
        }
        char tar = word[index];
        if (tar == board[row][col])
        {
            ignore[row][col] = 1;
            if (index == word.length() - 1)
            {
                final_ans = true;
                return;
            }
            index++;
            //up
            if (row - 1 >= 0)
            {
                loop(index, row - 1, col, ignore);
            }
            //down
            if (row + 1 <= board.size() - 1)
            {
                loop(index, row + 1, col, ignore);
            }
            //left
            if (col - 1 >= 0)
            {
                loop(index, row, col - 1, ignore);
            }
            if (col + 1 <= board[0].size() - 1)
            {
                loop(index, row, col + 1, ignore);
            }
        }
        else
        {
            return;
        }
    }
};
int main()
{
 
    vector<vector<char>> board = {
                                    {'a', 'a', 'a', 'a'}, 
                                    {'s', 'f', 'c', 's'},
                                    {'a', 'd', 'e', 'e'}
    };
    Solution abc;
    string word = "aaasaa";
    bool ans = abc.exist(board, word);
    cout << ans;
    return 0;
}