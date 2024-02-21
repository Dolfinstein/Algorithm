// 73 set matrix zeros
#include <iostream>
#include <vector>
using namespace std;
void disp_mat(vector<vector<int>> &vec);
int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0},
    {3, 4, 5, 2}, 
    {1, 3, 1, 5}};
    // cout<<"Hello World";
    int first = 1;  // 0代表要清掉
    int first_row = 1;
    int first_col = 1;
    vector<vector<int>> vec = matrix;
    if (vec[0][0] == 0)
    {
        first = 0;
        first_row = 0;
        first_col = 0;
    }
    else
    {
        for (int idx = 0; idx < vec[0].size(); idx++)
        {
            if (vec[0][idx] == 0)
            {
                first_row = 0;
                break;
            }
        }
        for (int idx = 0; idx < vec.size(); idx++)
        {
            if (vec[idx][0] == 0)
            {
                first_col = 0;
                break;
            }
        }
    }
    // disp_mat(matrix);
    for (int idx = 1; idx < vec.size(); idx++)
    {
        for (int jdx = 1; jdx < vec[0].size(); jdx++)
        {
            if (vec[idx][jdx] == 0)
            {
                vec[idx][0] = 0;
                vec[0][jdx] = 0;
            }
        }
    }
    for (int idx = 1; idx < vec.size(); idx++)
    {
        if (vec[idx][0] == 0)
        {
            for (int jdx = 1; jdx < vec[0].size(); jdx++)
            {
                vec[idx][jdx] = 0;
            }
        }
    }
    for (int jdx = 1; jdx < vec[0].size(); jdx++)
    {
        if (vec[0][jdx] == 0)
        {
            for (int idx = 1; idx < vec.size(); idx++)
            {
                vec[idx][jdx] = 0;
            }
        }
    }
    if (first == 0 )
    {
        for(int idx = 0; idx < vec.size(); idx++)
        {
            vec[idx][0] = 0;
        }
        for (int jdx = 0; jdx < vec[0].size(); jdx++)
        {
            vec[0][jdx] = 0;
        }
    }
    else
    {
        if (first_col == 0)
        {
            for(int idx = 0; idx < vec.size(); idx++)
        {
            vec[idx][0] = 0;
        }
        }
        if (first_row == 0)
        {
            for (int jdx = 0; jdx < vec[0].size(); jdx++)
        {
            vec[0][jdx] = 0;
        }    
        }
    }
    // cout << first_col;
    disp_mat(vec);
 
    return 0;
}
void disp_mat(vector<vector<int>> &vec)
{
    for (int idx = 0; idx < vec.size(); idx++)
    {
        for (int jdx = 0; jdx < vec[idx].size(); jdx++)
        {
            cout << vec[idx][jdx] << ' ';
        }
        cout << endl;
    }
}