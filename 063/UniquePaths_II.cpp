#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/unique-paths-ii/description/

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
     * Approach: DP
     *
     * Time complexity:  O(R * C)
     * Space complexity: O(C)
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int R = obstacleGrid.size(), C = obstacleGrid[0].size();
        vector<int> dp(C);
        for (int i = R - 1; i >= 0; --i) {
            for (int j = C - 1; j >= 0; --j) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (i == R - 1 && j == C - 1) dp[j] = obstacleGrid[i][j] ? 0 : 1;
                else if (i == R - 1) dp[j] = dp[j + 1];
                else if (j == C - 1) dp[j] = dp[j];
                else dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};

int main() {
//    vector<vector<int>> obstacleGrid = {{0, 0, 0},
//                                        {0, 1, 0},
//                                        {0, 0, 0}};
    vector<vector<int>> obstacleGrid = {{0, 1}};

    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}