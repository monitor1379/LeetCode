#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/array-partition-i/description/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int s = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() / 2; ++i)
            s += nums[i * 2];
        return s;
    }
};

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 4, 3, 2};
    display_vector(nums);
    sort(nums.begin(), nums.end());
    display_vector(nums);
    Solution s;
    cout << s.arrayPairSum(nums) << endl;
    return 0;
}
