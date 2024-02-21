// 125 valid palindrome 無腦法
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
 
 
 
int main()
{
    string s = "A man, a plan, a canal: Panama.";
    // 大寫變小寫
    unordered_map<char, char> alpha_convert = {
        {'A', 'a'},
        {'B', 'b'},
        {'C', 'c'},
        {'D', 'd'},
        {'E', 'e'},
        {'F', 'f'},
        {'G', 'g'},
        {'H', 'h'},
        {'I', 'i'},
        {'J', 'j'},
        {'K', 'k'},
        {'L', 'l'},
        {'M', 'm'},
        {'N', 'n'},
        {'O', 'o'},
        {'P', 'p'},
        {'Q', 'q'},
        {'R', 'r'},
        {'S', 's'},
        {'T', 't'},
        {'U', 'u'},
        {'V', 'v'},
        {'W', 'w'},
        {'X', 'x'},
        {'Y', 'y'},
        {'Z', 'z'}
    };
 
 
    unordered_set<char> set;
    for (auto it = alpha_convert.begin(); it != alpha_convert.end(); it++)
    {
        set.insert(it -> first);
        set.insert(it -> second);
    }
    int idx = 0;
    while(idx < s.length())
    {
        auto iter = set.find(s[idx]);
        if (iter == set.end()) //不存在
        {
            s.erase(idx, 1);
        }
        else
        {
            auto it = alpha_convert.find(s[idx]);
            if (it != alpha_convert.end())
            {
                s[idx] = it -> second;
            }
            idx++;
        }

        // idx++;

    }

    int left = 0;
    int right = s.length() - 1;
    while(left < right)
    {
        if (s[left] != s[right])
        {
            cout << "false";
            cout << endl << s;
            exit(0);
        }
        left++;
        right--;
    }
    cout << "true";
    cout << endl << s;

    return 0;
}