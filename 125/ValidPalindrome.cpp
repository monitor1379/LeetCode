#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isLetterOrDigits(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    char toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        else
            return c;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (!isLetterOrDigits(s[i])) ++i;
            while (!isLetterOrDigits(s[j])) --j;
            if (i >= j) return true;
            if (toLower(s[i]) != toLower(s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome("") << endl;
    cout << s.isPalindrome("a.") << endl;
    cout << s.isPalindrome("ab") << endl;
    cout << s.isPalindrome("0p") << endl;

    return 0;
}