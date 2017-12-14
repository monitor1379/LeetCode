#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/house-robber/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:

    /*
     * Approach #1: dp
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     */
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = max(nums[i] + (i >= 2 ? nums[i - 2] : 0), (i >= 1 ? nums[i - 1] : 0));
        }
        return nums[nums.size() - 1];
    }


    /*
     * Approach #2: 递归+memory
     */
    int rob2(vector<int> &nums) {
        vector<int> dpRob(nums.size(), -1);
        vector<int> dpNotRob(nums.size(), -1);
        return _rob(nums, 0, dpRob, dpNotRob);
    }

    int _rob(vector<int> &nums, int i, vector<int> &dpRob, vector<int> &dpNotRob) {
        if (i == nums.size())
            return 0;
        else if (i == nums.size() - 1)
            return nums[i];
        else {
            if (dpRob[i] == -1)
                dpRob[i] = nums[i] + _rob(nums, i + 2, dpRob, dpNotRob);
            if (dpNotRob[i] == -1)
                dpNotRob[i] = _rob(nums, i + 1, dpRob, dpNotRob);
            return max(dpRob[i], dpNotRob[i]);
        }
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 1, 10};
//    vector<int> nums = {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81,
//                        90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205,
//                        94, 205, 169, 241, 202, 144, 240};

    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}