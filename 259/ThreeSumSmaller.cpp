#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/3sum-smaller/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Request: solve it in O(n^2)
     *
     * Approach:注意这道题的要求！实际上对nums排序，并不影响输出结果的数量！
     * 证明：设有i < j < k 满足nums[i] + nums[j] + nums[k] < target,
     * 若对nums排序后的到nums[j] < nums[k] < nums[i], 则设
     * i' = j, j' = k, k' = i，得到i' < j' < k'，满足题意。
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        if (nums.size() < 3) return 0;
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
            result += twoSumSmaller(nums, target - nums[i], i + 1);
        return result;

    }

    int twoSumSmaller(vector<int> &nums, int target, int start) {
        int i = start, j = nums.size() - 1;
        int result = 0;
        while (i < j) {
            if (nums[i] + nums[j] >= target) --j;
            else {
                result += j - i;
                ++i;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-2, 0, 1, 3};
    Solution s;
    cout << s.threeSumSmaller(nums, 2) << endl;
    return 0;
}