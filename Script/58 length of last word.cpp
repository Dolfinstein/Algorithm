// 58 length of last word
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main()
{
    string s = "luffy is still joyboy";
    int len = s.length() - 1;
    int idx = 0;
    while(s[len - idx] != ' ')
    {
        idx++;
    }
    cout << idx;
 
    return 0;
}