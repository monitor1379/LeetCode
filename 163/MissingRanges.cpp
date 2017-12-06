#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/missing-ranges/description/

class Solution {
public:
    /*
     * 这题非常简单，但是用C++ int/double写会有上溢与下溢的可能
     * 弄了很久还是没有找到一种简洁优雅的写法，于是改成python（支持大整数运算）
     *
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {

    }
//    class Solution(object):
//        def findMissingRanges(self, nums, lower, upper):
//            """
//            :type nums: List[int]
//            :type lower: int
//            :type upper: int
//            :rtype: List[str]
//            """
//            pre = lower - 1
//            nums.append(upper + 1)
//            result = []
//            for i in nums:
//                if(i == pre + 2):
//                    result.append(str(pre + 1))
//                elif(i > pre + 2):
//                    result.append(str(pre + 1) + "->" + str(i - 1))
//                pre = i
//            return result
};

int main() {
//    vector<int> nums = {2147483647};
    vector<int> nums = {2147483647};

    Solution s;
    vector<string> result = s.findMissingRanges(nums, -2147483648, 2147483647);
    display_vector(result);
    return 0;
}