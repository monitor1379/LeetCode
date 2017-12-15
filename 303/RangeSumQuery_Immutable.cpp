#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/range-sum-query-immutable/description/

class NumArray {
private:
    vector<int> cumsum;
public:
    NumArray(vector<int> nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) cumsum.push_back(nums[i]);
            else cumsum.push_back(nums[i] + cumsum[i - 1]);
        }
    }

    int sumRange(int i, int j) {
        return cumsum[j] - (i == 0 ? 0 : cumsum[i - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main() {
    NumArray obj({-2, 0, 3, -5, 2, -1});
    cout << obj.sumRange(0, 2) << endl;
    cout << obj.sumRange(2, 5) << endl;
    cout << obj.sumRange(0, 5) << endl;
    return 0;
}