#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/minimum-path-sum/description/

template<typename T>
void display_2d_vector(vector<vector<T>> &v) {
    for (vector<T> vi: v) {
        for (T i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

class Solution {
public:
    /*
     * Approach: 2D DP
     *
     * for i = R - 1 to 0:
     *     for j = C - 1 to 0:
     *         dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]
     *
     * Time complexity:  O(R * C)
     * Space complexity: O(1)
     */
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int R = grid.size(), C = grid[0].size();
        for (int i = R - 1; i >= 0; --i) {
            for (int j = C - 1; j >= 0; --j) {
                if (i < R - 1 && j < C - 1)
                    grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
                else if (i == R - 1 && j < C - 1)
                    grid[i][j] += grid[i][j + 1];
                else if (i < R - 1 && j == C - 1)
                    grid[i][j] += grid[i + 1][j];
                else
                    grid[i][j] += 0;
            }
        }
        return grid[0][0];
    }
};


int main() {
//    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<int>> grid = {{1}};
    display_2d_vector(grid);

    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}