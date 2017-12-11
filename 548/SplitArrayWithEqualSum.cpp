#include <iostream>
#include <vector>
#include <set>

using namespace std;

// https://leetcode.com/problems/split-array-with-equal-sum/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:

    inline int getSum(vector<int> &cumsum, int start, int end) {
        return cumsum[end] - (start > 0 ? cumsum[start - 1] : 0);
    }

    /*
     * Approach #1: find i, find j, find k.
     *
     * Time complexity:  O(n^3)
     * Space complexity: O(n)
     *
     */
    bool splitArray2(vector<int> &nums) {
        if (nums.size() < 7) return false;
        vector<int> cumsum(nums);
        for (int i = 1; i < cumsum.size(); ++i)
            cumsum[i] += cumsum[i - 1];
        int i, j, k;
        int curSum = 0;
        int result = 0;
        for (i = 1; i <= nums.size() - 6; ++i) {
            curSum = getSum(cumsum, 0, i - 1);
            for (j = i + 2; j <= nums.size() - 4; ++j) {
                if (getSum(cumsum, i + 1, j - 1) == curSum) {
                    for (k = j + 2; k <= nums.size() - 2; ++k) {
                        if (getSum(cumsum, j + 1, k - 1) == curSum
                            && getSum(cumsum, k + 1, cumsum.size() - 1) == curSum) {
//                            cout << i << ", " << j << ", " << k << endl;
                            return true;
                        }

                    }
                }
            }
        }
        return false;
    }

    /*
     * Approach #2: find j, then find i, finally find k.
     *
     * Time complexity:  O(n^2)
     * Space complexity: O(n)
     *
     */
    bool splitArray(vector<int> &nums) {
        if (nums.size() < 7) return false;
        vector<int> cumsum(nums);
        for (int i = 1; i < cumsum.size(); ++i)
            cumsum[i] += cumsum[i - 1];
        set<int> s;
        int i, j, k;

        for (j = 3; j <= cumsum.size() - 4; ++j) {
            s.clear();
            for (i = 1; i <= j - 2; ++i) {
                if (cumsum[i - 1] == cumsum[j - 1] - cumsum[i])
                    s.insert(cumsum[i - 1]);
            }
            if (s.empty())
                continue;
            for (k = j + 2; k <= cumsum.size() - 2; ++k) {
                if (cumsum[k - 1] - cumsum[j] == cumsum[cumsum.size() - 1] - cumsum[k]) {
                    if (s.find(cumsum[k - 1] - cumsum[j]) != s.end()) {
                        return true;
                    }

                }
            }
        }
        return false;
    }
};


int main() {
    vector<int> nums = {1, 2, 1, 2, 1, 2, 1};
    display_vector(nums);

    Solution s;
    cout << s.splitArray(nums) << endl;
    return 0;
}