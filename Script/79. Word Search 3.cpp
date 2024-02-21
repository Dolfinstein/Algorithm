[23/12/8 上午10:33] 黃勁元(資訊處,高級辦事員)
// 79. Word Search

// third try, change board instead of building an ignore matrix

// but needs to be caucious to when to recover the board

// 另外有趣的點是可以把board的值變成'/0'

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

                // vector<vector<int>> ignore(board.size(), vector<int>(board[0].size(), 0));

                loop(index, idx, jdx);

            }

        }

        return final_ans;

    }

    void loop(int index, int row, int col)

    {

        if (final_ans == true)

        {

            return;

        }

        // cout << col << " " << row << endl;

        if (board[row][col] == '\0')

        {

            return;

        }

        char tar = word[index];

        if (tar == board[row][col])

        {

            if (index == word.length() - 1)

            {

                final_ans = true;

                return;

            }

            board[row][col] = '\0';

            index++;

            //up

            if (row - 1 >= 0)

            {

                loop(index, row - 1, col);

            }

            //down

            if (row + 1 <= board.size() - 1)

            {

                loop(index, row + 1, col);

            }

            //left

            if (col - 1 >= 0)

            {

                loop(index, row, col - 1);

            }

            if (col + 1 <= board[0].size() - 1)

            {

                loop(index, row, col + 1);

            }

            board[row][col] = tar;

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

    string word = "aaasas";

    bool ans = abc.exist(board, word);

    cout << ans;

    return 0;

}