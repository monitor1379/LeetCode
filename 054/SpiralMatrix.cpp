#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/spiral-matrix/description/

void display_2d_vector(vector<vector<int>> &v) {
    for (vector<int> vi: v) {
        for (int i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

void display_vector(vector<int> &v) {
    for (int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty()) return result;
        int R = matrix.size(), C = matrix[0].size();

        int r1 = 0, r2 = R - 1, c1 = 0, c2 = C - 1;
        while(r1 <= r2 && c1 <= c2)
        {
            // left to right
            for(int c = c1; c <= c2; ++c) result.push_back(matrix[r1][c]);
            // top to bottom
            for(int r = r1 + 1; r <= r2; ++r) result.push_back(matrix[r][c2]);
            // left to right
            if(r1 != r2)
                for(int c = c2 - 1; c >= c1; --c) result.push_back(matrix[r2][c]);
            // bottom up top
            if(c1 != c2)
                for(int r = r2 - 1; r > r1; --r) result.push_back(matrix[r][c1]);
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {6, 7, 8, 9}, {10, 11, 12, 13}};
    display_2d_vector(matrix);

    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    display_vector(result);
    return 0;
}