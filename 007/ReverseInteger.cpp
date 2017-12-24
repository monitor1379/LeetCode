#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        int x1 = x, x2 = 0;
        while (x1 != 0) {
            if (x2 * 10 / 10 != x2)
                return 0;
            x2 = x2 * 10 + x1 % 10;
            x1 = x1 / 10;
        }
        return x2;
    }
};

int main() {
    Solution s;
    cout << s.reverse(1534236469) << endl;
    return 0;
}