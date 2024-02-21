// 127. Word Ladder
 
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Solution {
private:
    vector<vector<int>> edge;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        int wordLen = beginWord.length();
        int sym = -1;
        for (int idx = 0; idx < wordList.size(); idx++)
        {
            if (beginWord == wordList[idx])
            {
                sym = idx;
            }
        }
        if (sym != -1)
        {
            wordList[sym] = wordList[wordList.size() - 1];
            wordList.pop_back();
        }
        for (int idx = 0; idx < wordList.size(); idx++)
        {
            int count = 0;
            for (int jdx = 0; jdx < wordLen; jdx++)
            {
                if (wordList[idx][jdx] != beginWord[jdx])
                {
                    count++;
                }
                if (count == 1)
                {
                    edge[0].push_back(idx + 1);
                    edge[idx + 1].push_back(0);
                }
            }
        }
        for (int idx = 0; idx < wordList.size(); idx++)
        {
            for (int jdx = idx + 1; jdx < wordList.size(); jdx++)
            {
                int count = 0;
                for (int zdx = 0; zdx < wordLen; zdx++)
                {
                    if (wordList[idx][zdx] != wordList[jdx][zdx])
                    {
                        count++;
                    }
                }
                if (count == 1)
                {
                    edge[idx + 1].push_back(jdx + 1);
                    edge[jdx + 1].push_back(idx + 1);
                }
            }
        }

        return -1;
    }
};
int main()
{
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    Solution abc;
    int ans = abc.ladderLength(beginWord, endWord, wordList);
    cout << "the answer is: " << ans;
 
    return 0;
}