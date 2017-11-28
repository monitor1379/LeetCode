#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/description/

void display_vector(vector<int> &v) {
    for (int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    // maintain the maximum sub array and minimum sub array.
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int imax = result, imin = result;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] < 0) swap(imax, imin);
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            result = max(result, imax);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {4, -5, 1, 2, 3, -4};

    display_vector(nums);
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}