#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0 && !isLetter(s[i])) --i;
        int j = i;
        while (j >= 0 && isLetter(s[j])) --j;
        return i - j;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;
    cout << s.lengthOfLastWord("race") << endl;
    cout << s.lengthOfLastWord("  race") << endl;
    cout << s.lengthOfLastWord("  race  ") << endl;
    cout << s.lengthOfLastWord("") << endl;
    cout << s.lengthOfLastWord("  ") << endl;

    return 0;
}