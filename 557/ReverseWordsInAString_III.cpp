#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution {
public:
    string reverseWords(string s) {
        int prev = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                for (int p = prev, q = i - 1; p < q; ++p, --q)
                    swap(s[p], s[q]);
                prev = i + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << "\"" << s.reverseWords("Let's take LeetCode contest") << "\"" << endl;
    cout << "\"" << s.reverseWords("Let's") << "\"" << endl;
    cout << "\"" << s.reverseWords(" ") << "\"" << endl;


    return 0;
}