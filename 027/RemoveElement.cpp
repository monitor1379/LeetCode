#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/remove-element/description/

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        if(nums.size() == 1)
            return nums[0] == val ? 0 : 1;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j)
        {
            while(nums[i] != val && i < nums.size()) ++i;
            while(nums[j] == val && j >= 0) --j;
            if(i > j) break;
            swap(nums[i], nums[j]);
        }
        return i;
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
    int val = 3;
    display_vector(nums);

    Solution s;
    cout << "New length: " <<s.removeElement(nums, val) << endl;
    display_vector(nums);
    return 0;
}
