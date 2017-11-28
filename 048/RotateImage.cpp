#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/rotate-image/description/

void display_2d_vector(vector<vector<int>> &v) {
    for (vector<int> vi: v) {
        for (int i: vi)
            cout << i << ", ";
        cout << endl;
    }
}


class Solution {
public:
    // First flip left to right, then swap the symmetry
    void rotate(vector<vector<int>> &matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = i; j < matrix.size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main() {
    vector<vector<int>> matrix = {{5,  1,  9,  11},
                                  {2,  4,  8,  10},
                                  {13, 3,  6,  7},
                                  {15, 14, 12, 16}};
    display_2d_vector(matrix);
    Solution s;
    s.rotate(matrix);
    display_2d_vector(matrix);
    return 0;
}