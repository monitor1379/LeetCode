#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/3sum-closest/discuss/

void display_vector(vector<int> &v) {
    for (int i: v)
        cout << i << ", ";
    cout << endl;
}


class Solution {
public:
    // Approach: like 3Sum.
    // Time complexity:  O(n^2)
    // Space complexity: O(1)
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        if(nums.size() <= 3) return accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2], a = 0, b, c;
        for(a = 0; a < nums.size() - 2; ++a)
        {
            b = a + 1;
            c = nums.size() - 1;
            while(b < c)
            {
                int t = nums[a] + nums[b] + nums[c];
                if(abs(target - t) < abs(target - result)) result = t;
                if(target == t) return t;
                if(target > t) ++b;
                else --c;
            }
        }
        return result;
    }
};

int main() {
//    vector<int> nums = {0, 1, 2, 5, 6, 8, 9, 10, 13};
//    vector<int> nums = {1, 1, 2, 5, 2, 3};
//    vector<int> nums = {-1, 2, 1, 4};
    vector<int> nums = {1, 1, 1, 1};
    display_vector(nums);

    Solution s;
    cout << s.threeSumClosest(nums, 0) << endl;
    return 0;
}