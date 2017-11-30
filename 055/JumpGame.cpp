#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/jump-game/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: DP
     *
     * curMinStep = 1
     * for i = n - 2 to 1:
     *     // if can jump, next step only need one, else need one more step then curMinStep.
     *     if nums[i] >= curMinStep:
     *         dp[i - 1] = 1;
     *     else:
     *         dp[i - 1]++;
     *
     * PS: the solution post on LeetCode is really GOOD!
     * https://leetcode.com/problems/jump-game/solution/
     */
    bool canJump(vector<int> &nums) {
        if(nums.empty()) return false;
        else if(nums.size() == 1) return true;
        else if(nums.size() == 2) return nums[0] >= 1;
        int curMinStep = 1;
        for(int i = nums.size() - 2; i >= 1; --i)
        {
            if(nums[i] >= curMinStep) curMinStep = 1;
            else curMinStep++;
        }
        return nums[0] >= curMinStep;
    }
};

int main() {
//    vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums = {3, 2, 1, 0, 4};

    Solution s;
    cout << s.canJump(nums) << endl;
    return 0;
}