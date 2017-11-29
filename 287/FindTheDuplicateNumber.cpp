#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/description/

void display_vector(vector<int> &v) {
    for (int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Note:
     * 1. You must not modify the array (assume the array is read only).
     * 2. You must use only constant, O(1) extra space.
     * 3. Your runtime complexity should be less than O(n2).
     * 4. There is only one duplicate number in the array, but it could be repeated more than once.
     *
     *
     * Cycle detection:
     * 1. https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
     * 2. http://blog.csdn.net/moneymoneyqian/article/details/52058571
     * 3. http://m.blog.csdn.net/gdymind/article/details/70544153
     *
     */
    int findDuplicate(vector<int>& nums) {
        if(nums.size() > 1)
        {
            int slow = nums[0], fast = nums[nums[0]];
            while(slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            slow = 0;
            while(slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;

    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3, 4, 5};
    display_vector(nums);

    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}