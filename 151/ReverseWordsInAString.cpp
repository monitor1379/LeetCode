#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    /*
     * Approach: first reverse the string, then reverse every word.
     *
     * Note:
     * 1. drop leading or trailing spaces.
     * 2. reduce multiple spaces to a single space.
     *
     * Time complexity:  O(n)
     * SPace complexity: O(1)
     * 
     */
    void reverseWords(string &s) {
        while (s.back() == ' ') s.pop_back();
        reverse(s.begin(), s.end());
        while (s.back() == ' ') s.pop_back();
        for (auto it = s.begin(); it != s.end();) {
            if (*it == ' ' && *(it + 1) == ' ')
                s.erase(it);
            else
                ++it;
        }

        int j = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                for (int p = j, q = i - 1; p < q; ++p, --q)
                    swap(s[p], s[q]);
                j = i + 1;
            }
        }
    }
};

int main() {
    Solution s;

    string str = " the   sky  is blue";
    s.reverseWords(str);
    cout << "\"" << str << "\"" << endl;


    str = "the ";
    s.reverseWords(str);
    cout << "\"" << str << "\"" << endl;

    str = " ";
    s.reverseWords(str);
    cout << "\"" << str << "\"" << endl;
    return 0;
}