#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/sum-of-square-numbers/description/

class Solution {
public:
    /*
     * Time complexity:  O(sqrt(c))
     * Space complexity: O(1)
     *
     */
    bool judgeSquareSum(int c) {
        for (int a = 0; a <= int(sqrt(c)); ++a) {
            int k = a * a;
            if (sqrt(c - k) == int(sqrt(c - k))) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    Solution s;
    cout << s.judgeSquareSum(4) << endl;
    cout << s.judgeSquareSum(5) << endl;

    return 0;
}