#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display_2d_vector(vector<vector<int>>& v)
{
    for(vector<int> vi: v)
    {
        for(int i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

void display_vector(vector<int>& v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    // DP
    // dp[i] = max(nums[i], dp[i - 1] + nums[i])
    // result = max(dp)
    int maxSubArray(vector<int>& nums)
    {
        vector<int> dp(nums);
        dp[0] = nums[0];
        int result = nums[0];
        for(int i = 1; i < dp.size(); ++i)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main()
{
//    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    display_vector(nums);
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}