#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/two-sum/description

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> result(2);

        for(size_t i = 0; i < nums.size(); ++i)
        {
            if(mp.find(nums[i]) == mp.end())
            {
                mp[target - nums[i]] = i;
            }
            else
            {
                result[0] = mp[nums[i]];
                result[1] = i;
                break;
            }
        }
        return result;
    }
};


void display(unordered_map<int, int> mp)
{
    unordered_map<int, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << ", " << it->second << endl;
    }

}

void display_vector(vector<int> v)
{
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); ++it)
        cout << *it << ", ";
    cout << endl;
}
int main()
{
    Solution s;
    vector<int> nums = {2, 8, 11, 15, 7};
    int target = 9;

    display_vector(nums);
    display_vector(s.twoSum(nums, target));
    return 0;
}
