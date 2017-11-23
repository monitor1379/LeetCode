#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/max-consecutive-ones/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int k = 0;
        int maxK = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i])
                ++k;
            else
            {
                maxK = max(maxK, k);
                k = 0;
            }
        }

        maxK = max(maxK, k);
        return maxK;
    }
};

int main()
{
//    vector<int> nums = {1};
//    vector<int> nums = {0};
//    vector<int> nums = {1, 1, 1};
//    vector<int> nums = {0, 0, 0};
//    vector<int> nums = {1, 1, 0, 1, 1, 1};
    vector<int> nums = {1, 1, 0, 1};
    display_vector(nums);

    Solution s;
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
