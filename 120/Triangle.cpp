#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/triangle/description/

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
    // DP
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty() || triangle[0].empty()) return 0;
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < triangle[i].size(); ++j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};

int main() {
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    display_2d_vector(triangle);

    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}