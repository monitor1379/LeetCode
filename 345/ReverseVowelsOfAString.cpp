#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

class Solution {
public:
    string reverseVowels(string s) {
        map<char, int> m{{'a', 1},
                         {'e', 1},
                         {'i', 1},
                         {'o', 1},
                         {'u', 1},
                         {'A', 1},
                         {'E', 1},
                         {'I', 1},
                         {'O', 1},
                         {'U', 1}};
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (m[s[i]] == 0) ++i;
            while (m[s[j]] == 0) --j;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("hello") << endl;
    cout << s.reverseVowels("leetcode") << endl;
    return 0;
}