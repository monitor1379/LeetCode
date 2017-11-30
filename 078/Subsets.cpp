#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/subsets/description/

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
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        sort(nums.begin(), nums.end());
        vector<int> path;
        backtrack(nums, 0, result, path);
        return result;

    }

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result, vector<int>& path) {
        for(int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            result.push_back(path);
            backtrack(nums, i + 1, result, path);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution s;
    vector<vector<int>> result = s.subsets(nums);
    display_2d_vector(result);
    return 0;
}