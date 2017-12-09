#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/subarray-product-less-than-k/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

// 重做一遍https://leetcode.com/problems/subarray-sum-equals-k/solution/
class Solution {
public:
    /*
     * Approach: Two pointers, sliding window.
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     *
     */
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (nums.empty() || k < 1) return 0;
        int i = 0, j = 0;
        int result = 0;
        int curProduct = 1;
        for (i = 0; i < nums.size(); ++i) {
            if (i >= j)  // 重置
                curProduct = 1;
            else if (i > 0)  // 左端往右移，除以前一个数
                curProduct /= nums[i - 1];

            // 开始寻找使得子数组积大于等于k的那个下标j
            for (j = max(i, j); j < nums.size(); ++j) {
                curProduct *= nums[j];
                // 如果找到，则除以该数，因为下轮for_j的循环还会乘以它
                if (curProduct >= k) {
                    curProduct /= nums[j];
                    break;
                }
            }
            result += j - i;
        }
        return result;
    }
};

int main() {
    vector<int> nums = {100, 5, 2, 6, 10};
    display_vector(nums);
    int k = 100;

    Solution s;
    cout << s.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}