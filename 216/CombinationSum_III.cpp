#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/combination-sum-iii/description/

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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(result, path, k, n, 1);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& path, int k, int remain, int start) {
        if(k == 1) {
            if(start <= remain && remain <= 9)
            {
                path.push_back(remain);
                result.push_back(path);
                path.pop_back();
            }
            return ;
        }

        for(int i = start; i <= 9; ++i) {
            path.push_back(i);
            backtrack(result, path, k - 1, remain - i, i + 1);
            path.pop_back();
        }
    }
};


int main() {
    Solution s;
    vector<vector<int>> result = s.combinationSum3(3, 24);
    display_2d_vector(result);
    return 0;
}