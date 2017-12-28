#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/range-addition-ii/description/

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
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        for (vector<int> op: ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }

    /*
     * Memory Limit Exceeded
     *
     */
    int maxCount2(int m, int n, vector<vector<int>> &ops) {
        if (ops.empty()) return m * n;
        vector<vector<int>> t(m, vector<int>(n, 0));

        for (vector<int> op: ops) {
            for (int i = 0; i < op[0]; ++i) {
                t[i][0] += 1;
                if (op[1] < n)
                    t[i][op[1]] -= 1;
            }
        }
        int maxNum = -1, cnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j > 0)
                    t[i][j] += t[i][j - 1];
                if (t[i][j] > maxNum) {
                    maxNum = t[i][j];
                    cnt = 1;
                } else if (t[i][j] == maxNum) {
                    cnt++;
                }

            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<int>> ops = {{2, 2},
                               {3, 3}};

    Solution s;
    cout << s.maxCount(3, 3, ops) << endl;


    return 0;
}