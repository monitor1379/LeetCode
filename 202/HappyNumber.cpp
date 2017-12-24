#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/happy-number/description/

class Solution {
public:
    /*
     * Approach: Floyd Cycle detection algorithm.
     */
    int next(int n) {
        int result = 0;
        while (n > 0) {
            result += (n % 10) * (n % 10);
            n /= 10;
        }
        return result;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast);
        return slow == 1;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
    cout << s.isHappy(27) << endl;
    cout << s.isHappy(0) << endl;
    return 0;
}