#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/candy-crush/description/

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
    bool updateFlags(vector<vector<int>> &board) {
        int R = board.size(), C = board[0].size();
        bool isStable = true;
        for (int i = R - 1; i >= 0; --i) {
            for (int j = 0; j < C; ++j) {
                if (j < C - 2 && abs(board[i][j]) > 0
                    && abs(board[i][j]) == abs(board[i][j + 1])
                    && abs(board[i][j]) == abs(board[i][j + 2])) {
                    board[i][j] = -abs(board[i][j]);
                    board[i][j + 1] = -abs(board[i][j]);
                    board[i][j + 2] = -abs(board[i][j]);
                    isStable = false;
                }
                if (i >= 2 && abs(board[i][j]) > 0
                    && abs(board[i][j]) == abs(board[i - 1][j])
                    && abs(board[i][j]) == abs(board[i - 2][j])) {
                    board[i][j] = -abs(board[i][j]);
                    board[i - 1][j] = -abs(board[i][j]);
                    board[i - 2][j] = -abs(board[i][j]);
                    isStable = false;
                }
            }
        }
        return isStable;
    }

    void crush(vector<vector<int>> &board) {
        for (int j = 0; j < board[0].size(); ++j) {
            int i, k = board.size() - 1;
            while (1) {
                // 从下往上，寻找第一个空洞
                while (k >= 0 && board[k][j] > 0) --k;
                if (k < 0) break;
                i = k - 1;

                // 从k往上，寻找第一个非空洞
                while (i >= 0 && board[i][j] <= 0) --i;

                if (i >= 0) {
                    board[k][j] = board[i][j];
                    board[i][j] = 0;
                } else {
                    board[k][j] = 0;
                }
                --k;
            }

        }
    }

    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        bool isStable;
        do {
            isStable = updateFlags(board);
            if (!isStable) crush(board);
        } while (!isStable);
        return board;
    }
};

int main() {
    vector<vector<int>> board = {{110, 5,   112, 113, 114},
                                 {210, 211, 5,   213, 214},
                                 {310, 311, 3,   313, 314},
                                 {410, 411, 412, 5,   414},
                                 {5,   1,   512, 3,   3},
                                 {610, 4,   1,   613, 614},
                                 {710, 1,   2,   713, 714},
                                 {810, 1,   2,   1,   1},
                                 {1,   1,   2,   2,   2},
                                 {4,   1,   4,   4,   1014}};

    Solution s;
    vector<vector<int>> result = s.candyCrush(board);
    display_2d_vector(result);
    return 0;
}