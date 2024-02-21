// 15 3sum
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
using namespace std;
void display(const vector<int> &vec);
int partition(vector<int>& arr, int low, int high);
void quickSort(std::vector<int>& arr, int low, int high);
void twosum(const vector<int> & vec, vector<vector<int>> &ans, int location);
 
 
int main()
{
    vector<int> nums = {-1, 0, 1, 0, 2, -1, -1, 2};

    vector<vector<int>> ans;
    // vector<int> ans_tmp;
    quickSort(nums, 0, nums.size() - 1);
    display(nums);
    int idx = 0;
    while(idx < (nums.size() - 2))
    {
        twosum(nums, ans, idx);
        // if(ans_tmp.size() != 0)
        // {
        //     ans.push_back(ans_tmp);
        // }
        while(nums[idx + 1] == nums[idx])
        {
            idx++;
        }
        idx++;
    }
    cout << ans.size();
    for (int jdx = 0; jdx < ans.size(); jdx++)
    {
        display(ans[jdx]);
    }

    return 0;
}
void display(const vector<int> &vec)
{
    cout << endl;
    for (int idx = 0; idx < vec.size(); idx++)
    {
        cout << vec[idx] << ' ';
    }
    cout << endl;
}

int partition(vector<int>& arr, int low, int high) 
{
   int pivot = arr[high]; // Choose the rightmost element as the pivot
   int i = (low - 1); // Initialize the index of the smaller element
 
   for (int j = low; j <= high - 1; j++) {
       // If the current element is smaller than or equal to the pivot
       if (arr[j] <= pivot) {
           i++;
           swap(arr[i], arr[j]);
       }
   }
 
   swap(arr[i + 1], arr[high]);
   return (i + 1);
}
 
// Function to perform Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
   if (low < high) {
       // Partition the array into two subarrays
       int pivotIndex = partition(arr, low, high);
 
       // Recursively sort the subarrays
       quickSort(arr, low, pivotIndex - 1);
       quickSort(arr, pivotIndex + 1, high);
   }
}
void twosum(const vector<int> & vec, vector<vector<int>>& ans,  int location)
{
    int left = location + 1;
    int right = vec.size() - 1;
    int pivot = vec[left - 1];
    // vector<vector<int>> ans;
    int target = -1 * (pivot);
    vector<int> tmp;
    while(left < right)
    {
        vector<int> ans_tmp = {pivot};
        if (vec[left] + vec[right] < target)
        {
            left++;
        }
        else if (vec[left] + vec[right] > target)
        {
            right--;
        }
        else
        {
            ans_tmp.push_back(vec[left]);
            ans_tmp.push_back(vec[right]);
            ans.push_back(ans_tmp);
            while(vec[left + 1] == vec[left])
            {
                left++;
            }
            while(vec[right - 1] == vec[right])
            {
                right++;
            }
            left++;
            right--;
        }
    }

}