#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/contains-duplicate/description/

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        map<int, int> m;
        for(int i: nums)
        {
            if(m[i] != 0)
                return true;
            else
                ++m[i];
        }
        return false;
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
    vector<int> nums = {3, 2, 1, 4, 2};
    display_vector(nums);
    Solution s;
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}
