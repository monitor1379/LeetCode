#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/palindrome-number/description/

class Solution {
public:
    /*
     * Approach: reverse x, then compare two numbers.
     *
     * Space complexity:  O(1)
     *
     */
    bool isPalindrome(int x) {
        if (x < 0 || x != 0 && x % 10 == 0) return false;
        int x1 = x, x2 = 0;
        while (x > 0) {
            x2 = x2 * 10 + x % 10;
            x /= 10;
        }
        return x1 == x2;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(12321) << endl;
    cout << s.isPalindrome(1) << endl;
    cout << s.isPalindrome(0) << endl;
    cout << s.isPalindrome(-1) << endl;
    return 0;
}