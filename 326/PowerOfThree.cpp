#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/power-of-three/description/

class Solution {
public:
    bool isPowerOfThree(int n) {
        double a = log10(n) / log10(3);
        return a == int(a);
    }
};

int main() {

    Solution s;
    cout << s.isPowerOfThree(0) << endl;
    cout << s.isPowerOfThree(1) << endl;
    cout << s.isPowerOfThree(3) << endl;
    cout << s.isPowerOfThree(12) << endl;
    cout << s.isPowerOfThree(27) << endl;
    cout << s.isPowerOfThree(243) << endl;

    return 0;
}