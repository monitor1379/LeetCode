#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string-ii/description/

class Solution {
public:
    void reverseWords(vector<char> &str) {
        reverse(str.begin(), str.end());
        int j = 0;
        for (int i = 0; i <= str.size(); ++i) {
            if (i == str.size() || str[i] == ' ') {
                for (int p = j, q = i - 1; p < q; ++p, --q)
                    swap(str[p], str[q]);
                j = i + 1;
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}