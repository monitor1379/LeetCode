#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/description/

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
     * Approach #1: Using extra space to store which row and column should be zeroes.
     *      Time complexity:  O(R * C)
     *      Space complexity: O(R + C)
     *
     * Approach #2: If matrix[i][j] is zero, then set matrix[i][0] and matrix[0][j] zero.
     * Because the first row and first column use the same flag matrix[0][0], we use
     * another flag isRow0ShouldBeZero to store the state of first row.
     *      Time complexity:  O(R * C)
     *      Space complexity: O(R + C)
     *
     */
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return ;
        int R = matrix.size(), C = matrix[0].size();

        bool isRow0ShouldBeZero = false;
        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    if(i != 0) matrix[i][0] = 0;
                    else isRow0ShouldBeZero = true;
                }
            }
        }
        for(int j = 1; j < C; ++j)
            if(matrix[0][j] == 0)
                for(int i = 1; i < R; ++i)
                    matrix[i][j] = 0;

        for(int i = 1; i < R; ++i)
            if(matrix[i][0] == 0)
                for(int j = 1; j < C; ++j)
                    matrix[i][j] = 0;

        if(matrix[0][0] == 0)
            for(int i = 1; i < R; ++i)
                matrix[i][0] = 0;

        if(isRow0ShouldBeZero)
            for(int j = 0; j < C; ++j)
                matrix[0][j] = 0;

    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 1, 4},
                                  {-5, 6, 0, -8},
                                  {0, 0, -5, 12}};
    display_2d_vector(matrix);

    Solution s;
    s.setZeroes(matrix);
    display_2d_vector(matrix);
    return 0;
}