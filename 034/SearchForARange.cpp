#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/search-for-a-range/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Request: O(logn) time complexity.
     *
     * Approach: Binary search:find the first index where target appears, and the last index where target appears.
     *
     * Time complexity:  O(logn)
     * Space complexity: O(1)
     *
     */
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result;
        if (nums.empty()) return {-1, -1};
        // 寻找第一个出现的target的下标
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        if (nums[low] != target) return {-1, -1};
        result.push_back(low);

        low = 0, high = nums.size() - 1;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] > target) high = mid;
            else low = mid + 1;
        }
        if (nums[low] != target)
            result.push_back(low - 1);
        else
            result.push_back(low);
        return result;
    }
};


int main() {
//    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 9};
//    vector<int> nums = {7, 7};
//    vector<int> nums = {1, 1, 1, 1, 2, 3, 4, 4, 5, 7, 7, 8, 8, 8, 9, 9, 9, 10};
    vector<int> nums = {};

//    display_vector(nums);
    Solution s;
    vector<int> result = s.searchRange(nums, 1);
    display_vector(result);
    return 0;
}