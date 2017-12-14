#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/paint-fence/description/

class Solution {
public:
    /*
     * Time complexity:  O(n)
     * Space complexity: O(1)
     */
    int numWays(int n, int k) {
        if (n == 0) return 0;
        else if (n == 1) return k;
        else {
            int diff = k;
            int same = 0;
            int tmp;
            for (int i = 1; i < n; ++i) {
                tmp = diff;
                diff = (diff + same) * (k - 1);
                same = tmp;
            }
            return same + diff;
        }

    }
};

int main() {
    Solution s;
    cout << s.numWays(3, 2) << endl;
    return 0;
}