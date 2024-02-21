// 20. Valid Parentheses
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    
    string s = "()[]{((()}";
    
    if (s.length() == 0)
    {
        exit(0);
    }
    vector<char> stack;
    for (int idx = 0; idx < s.length(); idx++)
    {
        if (s[idx] == '(')
        {
            stack.push_back(')');
        }
        else if (s[idx] == '[')
        {
            stack.push_back(']');
        }
        else if (s[idx] == '{')
        {
            stack.push_back('}');
        }
        else if (s[idx] == ')')
        {
            char tmp = stack.back();
            stack.pop_back();
            if (tmp != ')')
            {
                cout << "false";
                exit(0);
            }
        }
        else if (s[idx] == ']')
        {
            char tmp = stack.back();
            stack.pop_back();
            if (tmp != ']')
            {
                cout << "false";
                exit(0);
            }
        }
        else if (s[idx] == '}')
        {
            char tmp = stack.back();
            stack.pop_back();
            if (tmp != '}')
            {
                cout << "false";
                exit(0);
            }
        }
        
    }
    cout << "true";
    
    return 0;
}
