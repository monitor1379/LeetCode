#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: 此题可泛化为，给定两个有序数组，寻找在两个数组中第k小的数（k从1开始）。
     *
     * 思路：
     * 假设有两个数组A与B：
     *     A:  a0 < (a1) <  a2  < a3 < a4
     *     B:  b0 <  b1  < (b2) < b3 < b4
     *
     * 若寻找第5小的数，则在A中取第2个数:a1(k/2=2)，在B中取第3个数:b2(k-k/2=3)，将其进行比较。
     * 设：
     *      [a0, a1]为part1， [a2, a3, a4]为part2，
     *      [b0, b1, b2]为part3， [b3, b4]为part4
     *
     * 如果a1 < b2，则第k小的数不可能在part1（该区域的数只可能是第1小至第k-1小）
     * 和part4（该区域的数只可能是第k+1小至第len(A)+len(B)小。
     *
     * 例如：
     * 1. 第5小的数在【part2】：
     *          A: 1 (2) 3  4 [5]
     *          B: 6  7 (8) 9 10
     *
     * 2. 第5小的数在【part3】：
     *          A: 1 (2) 3 7 8
     *          B: 4 [5] (6) 9 10
     *
     * 所以去掉part1（必选）与part4（可选），得到新A'与新B'：
     *     A':  a2  < a3 < a4
     *     B':  b0 <  b1  < b2
     *
     * 则问题变成在A'与B'中寻找第k-(k/2)小的数，递归使用该方法即可。
     *
     * 因为每次寻找，k都减少一半，加上在该题中k=(n+m)/2，所以
     *
     * Time complexity:  O(log(k)) = O(log(n+m))
     * Space complexity: O(n + m)
     *
     */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int totalN = n1 + n2;
        if (totalN % 2 == 1)
            return findK(nums1, 0, n1, nums2, 0, n2, totalN / 2 + 1);
        else
            return (findK(nums1, 0, n1, nums2, 0, n2, totalN / 2)
                    + findK(nums1, 0, n1, nums2, 0, n2, totalN / 2 + 1)) / 2;
    }

    // 寻找第k小的数，k = [1, n1 + n2]
    double findK(vector<int> &nums1, int s1, int n1, vector<int> &nums2, int s2, int n2, int k) {
        if (n1 > n2) return findK(nums2, s2, n2, nums1, s1, n1, k);
        if (n1 == 0) return nums2[k - 1];
        if (n2 == 0) return nums1[k - 1];
        if (k == 1) return min(nums1[s1], nums2[s2]);
        int k1 = min(k / 2, n1), k2 = k - k1;
        if (nums1[s1 + k1 - 1] < nums2[s2 + k2 - 1]) {
            return findK(nums1, s1 + k1, n1 - k1, nums2, s2, k2, k - k1);
        } else if (nums1[s1 + k1 - 1] > nums2[s2 + k2 - 1]) {
            return findK(nums1, s1, k1, nums2, s2 + k2, n2 - k2, k - k2);
        } else
            return nums1[s1 + k1 - 1];
    }
};

int main() {
    vector<int> nums1 = {3};
    vector<int> nums2 = {1, 2};

    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}