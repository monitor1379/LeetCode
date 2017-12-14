#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/lonely-pixel-ii/description/

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
     * A little confuse of Rule 2.
     *
     * Time complexity:  O(R * C)
     *
     */
    int findBlackPixel(vector<vector<char>> &picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int result = 0;
        map<string, int> m;
        vector<int> colCnt(picture[0].size(), 0);

        for (int i = 0; i < picture.size(); ++i) {
            string s;
            for (int j = 0; j < picture[i].size(); ++j) {
                s += picture[i][j];
                if (picture[i][j] == 'B') colCnt[j] += 1;
            }
            m[s] += 1;
        }
        for (auto kv: m) {
            if (kv.second == N) {
                int rowBCnt = 0; // 统计该行一共有多少个B
                int validB = 0; // 统计改行一共有多少个有效的B，即列上的B数为N
                for (int j = 0; j < kv.first.size(); ++j) {
                    if (kv.first[j] == 'B') {
                        rowBCnt++;
                        if (colCnt[j] == N)
                            validB++;
                    }
                }
                if (rowBCnt == N) result += validB * N;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<char>> picture = {{'W', 'B', 'W', 'B', 'B', 'W'},
                                    {'W', 'B', 'W', 'B', 'B', 'W'},
                                    {'W', 'B', 'W', 'B', 'B', 'W'},
                                    {'W', 'W', 'B', 'W', 'B', 'W'}};

//    vector<vector<char>> picture = {{'W', 'B', 'W', 'B', 'B', 'W'},
//                                    {'B', 'W', 'B', 'W', 'W', 'B'},
//                                    {'W', 'B', 'W', 'B', 'B', 'W'},
//                                    {'B', 'W', 'B', 'W', 'W', 'B'},
//                                    {'W', 'W', 'W', 'B', 'B', 'W'},
//                                    {'B', 'W', 'B', 'W', 'W', 'B'}};

    Solution s;
    cout << s.findBlackPixel(picture, 3) << endl;
    return 0;
}