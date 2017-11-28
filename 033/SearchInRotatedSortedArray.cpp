#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

void display_vector(vector<int> &v) {
    for (int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    // Two-step binary search.
    // Time complexity:  O(logn)
    // Space complexity: O(1)
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int r = -1, l = 0, h = nums.size() - 1, m;
        // Step 1: binary search the index of smallest number
        while(l < h)
        {
            if(nums[l] < nums[h]) break;
            m = (l + h) / 2;
            if(nums[l] <= nums[m]) l = m + 1;
            else h = m;

        }
        // l is the index of smallest number

        // Step 2: binary search the target
        if(target <= nums[nums.size() - 1]) h = nums.size() - 1;
        else
        {
            h = l - 1;
            l = 0;
        }
        while(l < h)
        {
            m = (l + h) / 2;
            if(nums[m] < target) l = m + 1;
            else if (target < nums[m]) h = m;
            else return m;
        }
        return nums[l] == target ? l : -1;

    }
};

int main() {
//    vector<int> nums = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, -4, -3, -2, -1, 1, 2, 3};
//    vector<int> nums = {4, 5, 6, 14, 16, -4, -3, -2, -1, 1, 2, 3};
//    vector<int> nums = {4, -4, 3};
//    vector<int> nums = {2, 4, 1};
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    display_vector(nums);
    Solution s;
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << "--------------" << endl;
        cout << s.search(nums, nums[i]) << endl;
    }

    return 0;
}