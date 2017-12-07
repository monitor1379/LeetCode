#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

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
     * Approach #1 : DP，该题类似最长公共子字符串。
     * A: [1, 2, 3, 2, 1]
     * B: [3, 2, 1, 4, 7]
     *
     *   A| 1 2 3 2 1
     * --------------
     * B 3| 0 0 1 0 0
     *   2| 0 1 0 2 0
     *   1| 1 0 0 0 3
     *   4| 0 0 0 0 0
     *   7| 0 0 0 0 0
     *
     * Time complexity:  O(A * B)
     * Space complexity: O(A * B) or O(min(A, B))
     *
     */
    int findLength(vector<int> &A, vector<int> &B) {
        if (A.empty() || B.empty()) return 0;
        int R = B.size(), C = A.size();
        vector<vector<int>> dp(R, vector<int>(C, 0));
        int maxLength = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (A[j] == B[i]) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }
        return maxLength;
    }

    /*
     * Approach #2: Binary Search with Rolling Hash
     * https://leetcode.com/problems/maximum-length-of-repeated-subarray/solution/
     *
     */
};

int main() {
    vector<int> A = {1, 2, 3, 2, 1};
    vector<int> B = {3, 2, 1, 4, 7};

    Solution s;
    cout << s.findLength(A, B) << endl;
    return 0;
}