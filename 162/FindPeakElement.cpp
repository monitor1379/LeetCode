#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/find-peak-element/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: Binary search
     * Time complexity:  O(logn)
     * space complexity: O(1)
     */
    int findPeakElement(vector<int> &nums) {
        int low = 0, high = nums.size() - 1, mid = (low + high) / 2;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] < nums[mid + 1]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

int main() {
    Solution s;
    vector<int> nums = {6, 4, 3, 2, 1};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}