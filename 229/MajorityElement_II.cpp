#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/majority-element-ii/description/


void display_vector(vector<int> &v) {
    for (int i: v)
        cout << i << ", ";
    cout << endl;
}


class Solution {
public:
    /*
     * Request: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
     * The algorithm should run in linear time and in O(1) space.
     *
     * Approach: Boyer-Moore Majority Vote algorithm.
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     *
     */

    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        int cnt1 = 0;
        int candidate2 = 1;
        int cnt2 = 0;
        for(int i: nums)
        {
            if(i == candidate1) ++cnt1;
            else if(i == candidate2) ++cnt2;
            else if(cnt1 == 0)
            {
                candidate1 = i;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                candidate2 = i;
                cnt2 = 1;
            }
            else
            {
                --cnt1;
                --cnt2;
            }
        }
        vector<int> result;
        cnt1 = 0, cnt2 = 0;
        for(int i: nums)
        {
            if(i == candidate1) ++cnt1;
            else if(i == candidate2) ++cnt2;
        }
        if(cnt1 > nums.size() / 3) result.push_back(candidate1);
        if(cnt2 > nums.size() / 3) result.push_back(candidate2);
        return result;
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1, 3, 2, 1};
    display_vector(nums);

    Solution s;
    vector<int> result = s.majorityElement(nums);
    display_vector(result);
    return 0;
}