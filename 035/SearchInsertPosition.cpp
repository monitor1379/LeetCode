#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/search-insert-position/description/

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

class Solution
{
public:
    // Approach #1: linear search
    // Time complexity: O(n)
    int searchInsert1(vector<int>& nums, int target)
    {
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] < target)
                continue;
            else
                return i;
        return nums.size();
    }

    // Approach #2: binary search
    // Time complexity: O(log n)
    int searchInsert(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    Solution s;
    cout << s.searchInsert(nums, 0) << endl;
    cout << s.searchInsert(nums, 2) << endl;
    cout << s.searchInsert(nums, 5) << endl;
    cout << s.searchInsert(nums, 7) << endl;
    return 0;
}
