#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

template<typename T>
void display_2d_vector(vector<vector<T>> &v) {
    for (vector<T> vi: v) {
        for (T i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: Using positive-negative flag.
     *
     * Traversal nums: for every x in nums, set nums[x-1] to negative,
     * if nums[x-1] is already negative, then nums[x-1] appears more than once.
     *
     */
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) - 1] < 0) result.push_back(abs(nums[i]));
            else nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return result;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    Solution s;
    vector<int> result = s.findDuplicates(nums);
    display_vector(result);
    return 0;
}