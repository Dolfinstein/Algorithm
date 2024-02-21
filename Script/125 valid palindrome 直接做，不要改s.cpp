// 125 valid palindrome 直接做，不要改s
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
    // int idx = 0;
    int left = 0;
    int right = s.length() - 1;
    while(left < right)
    {
        while(left < right)
        {
            int sym = 2;
            auto it1 = set.find(s[left]);
            if (it1 == set.end()) //不存在
            {
                left++;
                sym--;
            }
            auto it2 = set.find(s[right]);
            if (it2 == set.end()) //不存在
            {
                right--;
                sym--;
            }
            if (sym == 2)
            {
                break;
            }
        }
        auto itt = alpha_convert.find(s[left]);
        auto itt2 = alpha_convert.find(s[right]);
        char lv;
        char rv;
        if (itt == alpha_convert.end())
        {
            lv = s[left];
        }
        else
        {
            lv = itt -> second;
        }
        if (itt2 == alpha_convert.end())
        {
            rv = s[right];
        }
        else
        {
            rv = itt2 -> second;
        }

        if (lv != rv)
        {
            cout << "false";
            exit(0);
        }
        left++;
        right--;
    }

    cout << "true";


    return 0;
}