#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/sort-colors/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: Because the numbers are either 0 or 1 or 2,
     * so we can count the appearance of 0 and 1 and 2.
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     */
    void sortColors(vector<int> &nums) {
        vector<int> cnt(3, 0);
        for (int i: nums)
            ++cnt[i];
        for (int i = 0; i < cnt[0]; ++i) nums[i] = 0;
        for (int i = cnt[0]; i < cnt[0] + cnt[1]; ++i) nums[i] = 1;
        for (int i = cnt[0] + cnt[1]; i < nums.size(); ++i) nums[i] = 2;
    }
};

int main() {
    vector<int> nums = {};
    display_vector(nums);
    Solution s;
    s.sortColors(nums);
    display_vector(nums);
    return 0;
}