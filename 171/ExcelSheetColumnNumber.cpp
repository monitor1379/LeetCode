#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/excel-sheet-column-number/description/

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (char c: s) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.titleToNumber("A") << endl;
    cout << s.titleToNumber("Z") << endl;
    cout << s.titleToNumber("AZ") << endl;

    return 0;
}