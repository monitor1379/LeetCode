#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        int d = INT_MIN;
        int k = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i - 1])
                ++k;
            else
            {
                d = max(d, k);
                k = 1;
            }
        }
        return max(d, k);
    }
};

int main()
{

    vector<int> nums = {1, 3, 4, 5};
//    vector<int> nums = {1, 3, 5, 4, 7};
//    vector<int> nums = {2, 2, 2};
//    vector<int> nums = {2};
//    vector<int> nums = {5, 4, 3, 2, 1};

    display_vector(nums);

    Solution s;
    cout << s.findLengthOfLCIS(nums) << endl;
    return 0;
}
