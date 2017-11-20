#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/move-zeroes/description/

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int i = 0;
        for(int j = 0; j < nums.size(); ++j)
        {
            if(nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
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
    vector<int> nums = {0, 1, 2, 3, 0, 7, 3, 0, 0, 3, 1};
    display_vector(nums);
    Solution s;
    s.moveZeroes(nums);
    display_vector(nums);
    return 0;
}
