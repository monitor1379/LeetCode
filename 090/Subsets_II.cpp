#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/subsets-ii/description/

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
     * Approach: Backtracking.
     *
     *
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result;
        result.push_back({});
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        backtrack(result, nums, 0, tmp);
        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &nums, int start, vector<int> tmp) {
        if (start >= nums.size()) return;
        int lastOne = -1;
        for (int i = start; i < nums.size(); ++i) {
            // Process the duplicate situation
            if (i == start) lastOne = nums[start];
            else if (nums[i] == lastOne) continue;
            else lastOne = nums[i];
            tmp.push_back(nums[i]);
            result.push_back(tmp);
            backtrack(result, nums, i + 1, tmp);
            tmp.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    Solution s;
    vector<vector<int>> result = s.subsetsWithDup(nums);
    display_2d_vector(result);
    return 0;
}