#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/valid-triangle-number/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach:
     *
     * 1. Brute force: O(n^3)
     * 2. Binary search k: O(n^2logn)
     * 3. Two pointers step by step: O(n^2)
     *
     */
    int triangleNumber(vector<int> &nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] != 0) {
                int k = i + 2;
                for (int j = i + 1; j < nums.size() - 1; ++j) {
                    for (; k < nums.size() && nums[i] + nums[j] > nums[k]; ++k);
                    result += k - j - 1;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 2, 3, 4};
    Solution s;
    cout << s.triangleNumber(nums) << endl;
    return 0;
}