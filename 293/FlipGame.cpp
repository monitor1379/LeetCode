#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/flip-game/description/

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
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result = {};
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string t = s;
                t[i] = '-';
                t[i + 1] = '-';
                result.push_back(t);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> result = s.generatePossibleNextMoves("++++");
    display_vector(result);

    result = s.generatePossibleNextMoves("");
    display_vector(result);

    return 0;
}