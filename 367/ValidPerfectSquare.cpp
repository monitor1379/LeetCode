#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/valid-perfect-square/description/

class Solution {
public:
    /*
     * Approach: Binary Search
     */
    bool isPerfectSquare2(int num) {
        if (num == 0 || num == 1) return true;
        int low = 1, high = num / 2, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            cout << low << ", " << mid << ", " << high << endl;
            if (num / mid < mid)
                high = mid - 1;
            else if (num / mid >= mid) {
                if (num == mid * mid) return true;
                low = mid + 1;
            }
        }
        return low * low == num;
    }

    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        int low = 1, high = num / 2, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            cout << low << ", " << mid << ", " << high << endl;
            if (num / mid <= mid) {
                if (num == mid * mid) return true;
                high = mid - 1;
            } else if (num / mid > mid) {
                low = mid + 1;
            }
        }
        return low * low == num;
    }
};

int main() {

    Solution s;
    cout << s.isPerfectSquare(681) << endl;

    return 0;
}