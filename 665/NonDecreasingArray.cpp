#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/non-decreasing-array/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    bool checkPossibility(vector<int>& nums)
    {
        if(nums.size() <= 2) return true;
        int hasFound = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i - 1] > nums[i])
            {
                if(hasFound) return false;
                hasFound = 1;
                if(i < 2) nums[i - 1] = nums[i];
                else if(nums[i - 2] < nums[i]) nums[i - 1] = nums[i];
                else nums[i] = nums[i - 1];

            }
        }
        return true;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
//    vector<int> nums = {1, 2, 1};
//    vector<int> nums = {3, 2, 1};
//    vector<int> nums = {2, 1};
//    vector<int> nums = {2};
//    vector<int> nums = {1, 1, 1, 4, 0, 3};
//    vector<int> nums = {2, 3, 3, 2, 4};


    display_vector(nums);

    Solution s;
    cout << s.checkPossibility(nums) << endl;
    return 0;
}
