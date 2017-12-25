#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int n) {
        string t;
        if (n == 0) return t;
        while (n != 0) {
            t.push_back((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }
        reverse(t.begin(), t.end());
        return t;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(0) << endl;
    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(52) << endl;
    return 0;
}