#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/reverse-string-ii/description/

class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0, n = s.size(), end;
        while (start < n) {
            end = min(start + k, n);
            reverse(s.begin() + start, s.begin() + end);
            start += 2 * k;
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseStr("abcdefg", 2) << endl;
    cout << s.reverseStr("abcdefg", 4) << endl;
    cout << s.reverseStr("abcdefg", 10) << endl;
    return 0;
}