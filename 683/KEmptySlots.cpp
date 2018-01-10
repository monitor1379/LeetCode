#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/k-empty-slots/description/

class Solution {
public:
    /*
     * Approach: Sliding Window.
     *
     * 说白了就是给定一个数组f与一个间隔k，寻找左下标left与右下标right，使得：
     * 1. left与right之间有k个数.
     * 2. 这k个数均大于f[left]和f[right].
     * 最后返回max(f[left], f[right])，如果存在多个结果，则返回min(max(f[left], f[right]))
     *
     * Time complexity:  O(n)
     * Space complexity: O(n)
     *
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); ++i)
            days[flowers[i] - 1] = i + 1;
        int left = 0, right = left + k + 1, res = INT_MAX;
        for (int i = 0; i < flowers.size(); ++i) {
            if (i == right) {
                res = min(res, max(days[left], days[right]));
                left = i;
                right = left + k + 1;
            } else if (days[left] > days[i] || days[i] < days[right]) {
                left = i;
                right = left + k + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    vector<int> flowers = {1, 2, 3};

    Solution s;
    cout << s.kEmptySlots(flowers, 1) << endl;
    return 0;
}