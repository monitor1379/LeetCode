#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int i = 0, j = numbers.size() - 1, k;
        while(1)
        {
            k = numbers[i] + numbers[j];
            if(k > target)
                --j;
            else if(k < target)
                ++i;
            else
                return {i + 1, j + 1};
        }
    }
};

int main()
{
    vector<int> nums = {1, 4, 6, 10};
    int target = 10;

    display_vector(nums);
    Solution s;
    display_vector(s.twoSum(nums, target));
    return 0;
}
