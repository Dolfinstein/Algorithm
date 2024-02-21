// 56. Merge Intervals
#include <iostream>
#include <vector>
using namespace std;
// Function to partition the array into two sub-arrays based on the pivot element
int partition(vector<vector<int>>& arr, int low, int high) {
    int pivot = arr[high][0]; // Choose the pivot as the last element
    int i = (low - 1); // Initialize the index of the smaller element
 
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j][0] <= pivot) {
            i++; // Increment index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void disp_mat(vector<vector<int>> &vec);
 
// Function to perform the Quick Sort
void quickSort(vector<vector<int>>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays and get the pivot element
        int pivot = partition(arr, low, high);
 
        // Recursively sort the sub-arrays
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
 
int main() {
    vector<vector<int>> interval = {{1, 4}, {4, 5}};
    int n = interval.size();
    vector<vector<int>> ans;
    vector<int> last;
 
    quickSort(interval, 0, n - 1);
 
    // cout << "\nSorted Array: ";
    // for (int i = 0; i < n; i++) {
    //     cout << "{" << interval[i][0] << ", " << interval[i][1] << "}, ";
    // }
 
    last = interval[0];
    ans.push_back(last);
    for (int idx = 1; idx < n; idx++)
    {
        if (interval[idx][0] <= last[1])
        {
            if (interval[idx][1] <= last[1])
            {
                // do nothing;
            }
            else // interval[idx][1] > last[1]
            {
                last[1] = interval[idx][1];
                ans.pop_back();
                ans.push_back(last);
            }
        }
        else
        {
            last = interval[idx];
            ans.push_back(last);
        }
    }
    disp_mat(ans);
    return 0;
}
 
 
void disp_mat(vector<vector<int>> &vec)
{
    for (int idx = 0; idx < vec.size(); idx++) 
    {
        for (int jdx = 0; jdx < vec[idx].size(); jdx++) 
        { 
            if (vec[idx][jdx] < 0)
            {
                cout << vec[idx][jdx] << ' ';
            } 
            else
            { 
                cout << ' ' << vec[idx][jdx] << ' ';
            }
        }
 
        cout << endl;
 
    }
 
}