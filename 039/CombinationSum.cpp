#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/combination-sum/description/

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
     * Approach: Backtracking && Depth-first search.
     *
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrack(candidates, target, result, path, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int remain, vector<vector<int>>& result, vector<int>& path, int start)
    {
        if(remain == 0) result.push_back(path);
        else if(remain < 0) return ;
        for(int i = start; i < candidates.size(); ++i)
        {
            path.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], result, path, i);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {7, 3, 2, 6};
    Solution s;
    vector<vector<int>> result = s.combinationSum(nums, 10);
    display_2d_vector(result);
    return 0;
}