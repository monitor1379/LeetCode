#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

// https://leetcode.com/problems/contains-duplicate-ii/description/

class Solution
{
public:
    // 注意理解题意：只要存在一对i与j满足条件即为真，无需所有的i与j都满足。
    // LeetCode: 49ms
    bool containsNearbyDuplicate2(vector<int>& nums, int k)
    {
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]].push_back(i);
            if(m[nums[i]].size() >= 2 && m[nums[i]][m[nums[i]].size() - 1] - m[nums[i]][m[nums[i]].size() - 2] <= k)
                return 1;
        }
        return 0;
    }

    // 滑动窗口
    // LeetCode: set: 38ms
    // LeetCode: unordered_set: 26ms
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
            if(s.size() > k)
                s.erase(nums[i - k]);
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
    vector<int> nums = {1, 2, 3};

    int k = 0;
    display_vector(nums);

    Solution s;
    cout << "ContainsNearbyDulicat: " << s.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}
