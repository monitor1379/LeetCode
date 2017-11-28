#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

void display_vector(vector<int> &v) {
    for (int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    // Binary search.
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = (low + high) / 2;
        while(low < high)
        {
            if(nums[low] < nums[high]) return nums[low];
            cout << low << ", " << mid << ", " << high <<endl;
            mid = (low + high) / 2;
            if(mid == low) break;
            if(nums[mid] < nums[high]) high = mid;
            else if(nums[low] < nums[mid]) low = mid;
        }
        return min(nums[low], nums[high]);
    }
};

int main() {
//    vector<int> nums = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, -4, -3, -2, -1, 1, 2, 3};
//    vector<int> nums = {4, 5, 6, 14, 16, -4, -3, -2, -1, 1, 2, 3};
//    vector<int> nums = {4, -4, 3};
    vector<int> nums = {4, 5, 1, 2, 3};

    display_vector(nums);
    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}