#include <iostream>
#include <map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/two-sum/description

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> m;
        vector<int> result;

        for(size_t i = 0; i < nums.size(); ++i)
        {
            if(m.find(nums[i]) == m.end())
            {
                m[target - nums[i]] = i;
            }
            else
            {
                result.push_back(m[nums[i]]);
                result.push_back(i);
            }
        }
        return result;
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
    vector<int> nums = {1, 2, 9, 7, 10};
    int target = 9;

    Solution s;
    display_vector(s.twoSum(nums, target));


    return 0;
}
