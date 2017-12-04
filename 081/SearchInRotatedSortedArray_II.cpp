#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        if (nums.empty()) return false;
        if (nums.size() == 1) return nums[0] == target;

        int low = 0, high = nums.size() - 1, mid;

        while (low < high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[high]) {
                if(nums[mid] > target && nums[low] <= target) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            } else if(nums[mid] < nums[high]){
                if(nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            } else {
                --high;
            }
        }
        return nums[low] == target;
    }
};


int main() {
//    vector<int> nums = {7, 7, 7, 8, 8, 8, 8, 8, 8, 1, 2, 3, 4, 4, 4, 5};
//    vector<int> nums = {4, 1};
//    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5};
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    display_vector(nums);

    Solution s;
    cout << s.search(nums, 8) << endl;
    cout << s.search(nums, 9) << endl;
    cout << s.search(nums, 10) << endl;
    cout << s.search(nums, 1) << endl;
    cout << s.search(nums, 2) << endl;
    return 0;
}