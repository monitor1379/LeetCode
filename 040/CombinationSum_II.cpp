#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/combination-sum-ii/description/

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
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        if (candidates.empty()) return {};
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(result, candidates, target, 0, path);
        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &candidates, int remain, int start, vector<int> &path) {
        if (remain < 0) return;
        else if (remain == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i != start && candidates[i] == candidates[i - 1])
                continue;
            if (remain < candidates[i])
                break;
            path.push_back(candidates[i]);
            backtrack(result, candidates, remain - candidates[i], i + 1, path);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution s;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    display_2d_vector(result);
    return 0;
}