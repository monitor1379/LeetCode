#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("aba") << endl;
    cout << s.validPalindrome("abbccbda") << endl;
    cout << s.validPalindrome(
            "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga")
         << endl;
    return 0;
}