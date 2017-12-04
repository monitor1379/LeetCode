#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix/description/

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
    * Approach: Treat it as a sorted 1D array.
    */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int R = matrix.size(), C = matrix[0].size();
        int low = 0, high = R * C - 1, mid = (low + high) / 2;
        int r, c;
        while (low < high) {
            mid = (low + high) / 2;
            r = mid / C;
            c = mid % C;
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] < target) low = mid + 1;
            else high = mid;
        }
        r = low / C;
        c = low % C;
        return matrix[r][c] == target;
    }

};


int main() {
//    vector<vector<int>> matrix = {{1,  3,  5,  7},
//                                  {10, 11, 16, 20},
//                                  {23, 30, 34, 50},
//                                  {53, 60, 64, 70}};
    vector<vector<int>> matrix = {{1}};


    Solution s;

    cout << s.searchMatrix(matrix, 0) << endl;
    return 0;
}