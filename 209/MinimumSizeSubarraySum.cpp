#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: Two pointers.
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     *
     */
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.empty()) return 0;
        int low = 0, high = 0;
        int minLen = nums.size(), curSum = nums[0];
        bool hasSubArray = false;
        while (low < nums.size()) {
//            cout << low << ", " << high << ": " << curSum << ", " << minLen << endl;
            if (curSum < s) {
                if (high < nums.size() - 1) {
                    ++high;
                    curSum += nums[high];
                } else {
                    break;
                }
            } else {
                hasSubArray = true;
                minLen = min(minLen, high - low + 1);
                curSum -= nums[low];
                ++low;
            }
        }
        return hasSubArray ? minLen : 0;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution s;
    cout << s.minSubArrayLen(7, nums) << endl;
    return 0;
}