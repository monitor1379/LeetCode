#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/power-of-two/description/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (log10(n) / log10(2)) == int(log10(n) / log10(2));
    }
};

int main() {

    Solution s;

    cout << s.isPowerOfTwo(0) << endl;
    cout << s.isPowerOfTwo(1) << endl;
    cout << s.isPowerOfTwo(2) << endl;

    return 0;
}