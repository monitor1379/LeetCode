#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/reverse-string/description/

class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            swap(s[i], s[j]);
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseString("123123L:") << endl;
    return 0;
}