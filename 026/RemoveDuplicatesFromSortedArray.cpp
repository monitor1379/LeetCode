#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = 0; j < nums.size(); ++j)
        {
            if(nums[i] != nums[j])
            {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
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
    vector<int> nums = {};
//    vector<int> nums = {1, 1, 2};
//    vector<int> nums = {1, 1, 1, 1};
    display_vector(nums);
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
