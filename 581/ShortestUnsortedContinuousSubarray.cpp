#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:

    // Approach #1: Using sorting.
    // Time complexity:  O(nlogn)
    // Space complexity: O(n)
    int findUnsortedSubarray(vector<int>& nums)
    {
        if(nums.size() == 1) return 0;
        int i = nums.size(), j = -1;
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        for(int k = 0; k < nums.size(); k++)
        {
            if(nums[k] != sortedNums[k])
            {
                i = min(i, k);
                j = max(j, k);
            }
        }
        return j > i ? j - i + 1 : 0;
    }


    // Approach #2: find the minimum and maximum number of unsorted array firstly, then re-scan the array.
    // Time complexity:  O(n)
    // Space complexity: O(1)
    // TODO Uncompleted
    int findUnsortedSubarray2(vector<int>& nums)
    {
        int minimum = INT_MAX, maximum = INT_MIN;
        bool isUnsorted = false;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i < nums.size() - 1 && nums[i] > nums[i + 1])
                isUnsorted = true;
            if(isUnsorted)
            {
                minimum = min(minimum, nums[i]);
                maximum = max(maximum, nums[i]);
            }
        }



    }
};

int main()
{
    vector<int> nums = {1, 4, 3, 4, 5, 4, 7};
    display_vector(nums);

    Solution s;
    cout << s.findUnsortedSubarray(nums) << endl;
    return 0;
}
