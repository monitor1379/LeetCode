#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

template<typename T>
void display_2d_vector(vector<vector<T>> &v) {
    for (vector<T> vi: v) {
        for (T i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    // TODO: 可能存在没有pivot的情况（正常升序）
    bool search(vector<int> &nums, int target) {
        if(nums.empty()) return false;
        if(nums.size() == 1) return nums[0] == target;

        int low = 0, high = nums.size() - 1, mid;
        int n = nums.size();
        while (low < high) {
            while(nums[low] == nums[low + 1]) ++low;
            while(nums[high] == nums[high - 1]) --high;
            if(nums[low] <= nums[high]) break;

            mid = (low + high) / 2;
//            cout << low << ", " << mid << ", " << high << endl;
            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }

        }
//        cout << low << ": " << nums[low] << endl;
//        cout << low << ", " << mid << ", " << high << endl;

        if(target >= nums[0]) {
            high = low - 1;
            low = 0;
        } else {
            high = nums.size() - 1;
        }

//        cout << "===================" << endl;
        while (low < high) {
            while(nums[low] == nums[low + 1]) ++low;
            while(nums[high] == nums[high - 1]) --high;
            mid = (low + high) / 2;

//            cout << low << ", " << mid << ", " << high << endl;
            if (nums[mid] < target) {
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid;
            } else {
                return true;
            }
        }
        return nums[low] == target;
    }
};


int main() {
//    vector<int> nums = {7, 7, 7, 8, 8, 8, 8, 8, 8, 1, 2, 3, 4, 4, 4, 5};
//    vector<int> nums = {4, 1};
    vector<int> nums = {1, 2, 3, 4, 5};
    display_vector(nums);

    Solution s;
    cout << s.search(nums, 1) << endl;
    cout << s.search(nums, 2) << endl;
    cout << s.search(nums, 3) << endl;
    cout << s.search(nums, 4) << endl;
    return 0;
}