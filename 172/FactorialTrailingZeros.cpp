#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution {
public:
    /*
     * Approach: count the number of 5.
     */
    int trailingZeroes(int n) {
        return n == 0 ? 0 : (n / 5 + trailingZeroes(n / 5));
    }
};

int main() {
    Solution s;
    cout << s.trailingZeroes(1) << endl;
    cout << s.trailingZeroes(5) << endl;
    cout << s.trailingZeroes(10) << endl;
    cout << s.trailingZeroes(25) << endl;
    cout << s.trailingZeroes(125) << endl;
    return 0;
}