#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int low = 0, high = x, mid, p;
        while (low < high) {
            // 注意，如果是这种做法可能会造成上溢
            // mid = (low + high + 1) / 2;
            mid = low + (high - low) / 2;

            if (x / mid < mid) high = mid - 1;
            else {
                if (mid + 1 > x / (mid + 1)) return mid;
                else low = mid + 1;
            }
        }
        return high;
    }
};

int main() {

    Solution s;
    for (int i = 0; i <= 100; ++i) {
        cout << s.mySqrt(i) << ", " << i << endl;
    }
    cout << s.mySqrt(2147483647) << endl;

    return 0;
}