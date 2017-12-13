#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/lonely-pixel-i/description/

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
     * Time complexity:  O(R * C)
     * Space complexity: O(R + C)
     */
    int findLonelyPixel(vector<vector<char>> &picture) {
        if (picture.empty() || picture[0].empty()) return 0;
        vector<int> R(picture.size(), 0), C(picture[0].size(), 0);

        for (int i = 0; i < picture.size(); ++i) {
            for (int j = 0; j < picture[0].size(); ++j) {
                if (picture[i][j] == 'B') {
                    ++R[i];
                    ++C[j];
                }
            }
        }
        int rCnt = 0, cCnt = 0;
        for (int i: R)
            if (i == 1)
                ++rCnt;
        for (int i: C)
            if (i == 1)
                ++cCnt;
        return min(rCnt, cCnt);
    }
};

int main() {
    vector<vector<char>> picture = {{'W', 'W', 'B'},
                                    {'W', 'B', 'W'},
                                    {'B', 'W', 'W'}};

    Solution s;
    cout << s.findLonelyPixel(picture) << endl;
    return 0;
}