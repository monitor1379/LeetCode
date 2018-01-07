#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// https://leetcode.com/problems/number-of-islands/description/

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

class Solution2 {
public:

    /*
     * Approach:  DFS.
     *
     * 深度优先搜索：每找到一个岛屿，计数+1，然后使用深度优先搜索消除该岛屿。
     *
     * Time complexity:  O(R * C)
     * Space complexity: O(R * C) if grid is filled with '1'
     *
     */
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int R = grid.size(), C = grid[0].size();
        int result = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    // 深度优先搜索，消除岛屿
    void dfs2(vector<vector<char>> &grid, int i, int j) {
        int R = grid.size(), C = grid[0].size();
        grid[i][j] = 0;
        if (i >= 1 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (i <= R - 2 && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (j >= 1 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if (j <= C - 2 && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
};


class Solution3 {
public:

    /*
     * Approach:  BFS.
     *
     *
     * Time complexity:  O(R * C)
     * Space complexity: O(min(R, C))
     *
     * 当地图全是'1'时，队列q里保存的pair数最多的情况，是当扫描到对角线的时候。
     *
     */
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int R = grid.size(), C = grid[0].size();
        int result = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == '1') {
                    result++;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> &p = q.front();
                        q.pop();
                        int r = p.first, c = p.second;
                        if (r >= 0 && r < R && c >= 0 && c < C) {
                            if (grid[r][c] == '1') {
                                q.push({r - 1, c});
                                q.push({r + 1, c});
                                q.push({r, c - 1});
                                q.push({r, c + 1});
                            }
                            grid[r][c] = '0';
                        }
                    }
                }
            }
        }
        return result;
    }
};


class Solution {
public:


    /*
     * Approach: Union Find(aka Disjoint Set).
     *
     *
     * Time complexity:  O()
     * Space complexity: O()
     *
     *
     */
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int R = grid.size(), C = grid[0].size();
        vector<int> parent(R * C, -1);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                // TODO
            }
        }
    }


};

int main() {
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};

    Solution s;
    cout << s.numIslands(grid) << endl;
    return 0;
}