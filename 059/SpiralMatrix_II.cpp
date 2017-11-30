#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/spiral-matrix-ii/description/

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
    vector<vector<int>> generateMatrix(int n) {
        if(n < 0) return {{}};

        vector<vector<int>> m(n, vector<int>(n));
        int k = 1, r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;
        while(r1 <= r2 && c1 <= c2) {
            for(int c = c1; c <= c2; ++c) m[r1][c] = k++;
            for(int r = r1 + 1; r <= r2; ++r) m[r][c2] = k++;
            if(r1 < r2)  for(int c = c2 - 1; c >= c1; c--) m[r2][c] = k++;
            if(c1 < c2) for(int r = r2 - 1; r > r1; r--) m[r][c1] = k++;
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return m;
    }
};

int main() {
    Solution s;
    vector<vector<int>> result = s.generateMatrix(5);
    display_2d_vector(result);
    return 0;
}