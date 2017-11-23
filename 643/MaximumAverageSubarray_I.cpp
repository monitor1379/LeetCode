#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// https://leetcode.com/problems/maximum-average-subarray-i/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double average = 0;
        double maxAverage = 0;
        for(int i = 0; i < k; ++i) average += nums[i];
        maxAverage = average;
        for(int i = k; i < nums.size(); ++i)
        {
            average += nums[i] - nums[i - k];
            maxAverage = max(average, maxAverage);
        }
        return maxAverage / k;
    }
};

int main()
{
//    vector<int> nums = {1, 12, -5, -6, 50, 3};
//    vector<int> nums = {1, 12, 5};
//    vector<int> nums = {10, 1, 1, 4, 12, -45};
    vector<int> nums = {-3};

    display_vector(nums);

    Solution s;
    cout << s.findMaxAverage(nums, 1) << endl;
    return 0;
}
