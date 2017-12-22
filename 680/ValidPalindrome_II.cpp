#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/valid-palindrome-ii/description/

template<typename T>
void display_2d_vector(vector<vector<T>> &v) {
    for (vector<T> vi: v) {
        for (T i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

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