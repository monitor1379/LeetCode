#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/game-of-life/description/

void display_2d_vector(vector<vector<int>> &v) {
    for (vector<int> vi: v) {
        for (int i: vi)
            cout << i << ", ";
        cout << endl;
    }
}


class Solution {
public:
    /*
     * Approach: using 2 bits to store the states.
     * 00 -> dead(next), dead(current)
     * 01 -> dead(next), live(current)
     * 10 -> live(next), dead(current)
     * 11 -> live(next), live(current)
     *
     * Get current state: s & 1
     * Update next state:
     *      - dead(next): s & 1
     *      - live(next): s & 3
     * Update to next state: s >> 1
     *
     */
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return ;
        int R = board.size(), C = board[0].size();
        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                int s = -(board[i][j] & 1);
                for(int p = max(i - 1, 0); p <= min(i + 1, R - 1); ++p)
                {
                    for(int q = max(j - 1, 0); q <= min(j + 1, C - 1); ++q)
                    {
                        s += board[p][q] & 1;
                    }
                }
                // current is live
                if(board[i][j] & 1)
                {
                    if(s == 2 || s == 3) board[i][j] = 3;
                    else board[i][j] = 1;
                }
                else
                {
                    if(s == 3) board[i][j] = 2;
                    else board[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                board[i][j] >>= 1;
    }
};

int main() {
    vector<vector<int>> board = {{0, 0, 0}, {0, 0, 1}, {1, 0, 1}};
    display_2d_vector(board);

    Solution s;
    s.gameOfLife(board);
    display_2d_vector(board);
    return 0;
}