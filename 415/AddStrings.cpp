#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0;
        string result;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0) {
            c += (i >= 0 ? (num1[i] - '0') : 0) + (j >= 0 ? (num2[j] - '0') : 0);
            result.push_back(c % 10 + '0');
            c /= 10;
            --i;
            --j;
        }
        if (c > 0) result.push_back(c + '0');
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {

    Solution s;
    cout << s.addStrings("9", "5") << endl;

    return 0;
}