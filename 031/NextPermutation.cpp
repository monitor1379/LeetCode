#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/next-permutation/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Request: 寻找下一个全排列。
     *
     * http://blog.csdn.net/laojiu_/article/details/51115352
     * 设P是1～n的一个全排列:p=p1p2......pn=p1p2......pj-1pjpj+1......pk-1pkpk+1......pn
     * 1. 从排列的右端开始，找出第一个比右边数字小的数字的序号j，即 j=max{i|pi<pi+1}
     * 2. 在pj的右边的数字中，找出所有比pj大的数中最小的数字pk，即 k=max{i|pi>pj}（右边的数从右至左是递增的，因此k是所有大于pj的数字中序号最大者）
     * 3. 对换pj，pk
     * 4. 再将pj+1......pk-1pkpk+1......pn倒转得到排列p'=p1p2.....pj-1pjpn.....pk+1pkpk-1.....pj+1，这就是排列p的下一个字典序排列。
     *
     */
    void nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1) return;
        int i, j;
        for (i = nums.size() - 2; i >= 0; --i)
            if (nums[i] < nums[i + 1])
                break;
        if (i < 0) {
            for (int p = 0, q = nums.size() - 1; p < q; ++p, --q)
                swap(nums[p], nums[q]);
            return;
        }
        for (j = nums.size() - 1; j > i; --j)
            if (nums[j] > nums[i])
                break;
        swap(nums[i], nums[j]);
        for (int p = i + 1, q = nums.size() - 1; p < q; ++p, --q)
            swap(nums[p], nums[q]);
    }
};


int main() {
    vector<int> nums = {5, 1, 1};
    display_vector(nums);
    Solution s;
    s.nextPermutation(nums);
    display_vector(nums);
    return 0;
}