#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/4sum/description/

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
     * TODO: How to avoid duplicates?
     */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> result;
        for(int i = 0; i < nums.size() - 3; ++i) {
            path.push_back(nums[i]);
            threeSum(nums, target - nums[i], i + 1, result, path);
            path.pop_back();
        }
        return result;
    }

    void threeSum(vector<int>& nums, int target, int start, vector<vector<int>>& result, vector<int>& path) {
        for(int i = start; i < nums.size() - 2; ++i) {
            if(i > start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            twoSum(nums, target - nums[i], i + 1, result, path);
            path.pop_back();
        }
    }


    void twoSum(vector<int>& nums, int target, int start, vector<vector<int>>& result,  vector<int>& path) {
        int i = start, j = nums.size() - 1;
        while(i < j)
        {
            int k = nums[i] + nums[j];
            if(target > k) ++i;
            else if(target < k) --j;
            else {
                path.push_back(nums[i]);
                path.push_back(nums[j]);
                result.push_back(path);
                path.pop_back();
                path.pop_back();
                ++i;
                --j;
            }
        }
    }
};

int main() {
//    vector<int> nums = {1, 0, -1, 0, -2, 2};
//    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<int> nums = {-3, -3, -3, -3, 0, 0, 3, 3, 6, 6, 9};

    display_vector(nums);
    Solution s;
    vector<vector<int>> result = s.fourSum(nums, 0);
    display_2d_vector(result);
    return 0;
}