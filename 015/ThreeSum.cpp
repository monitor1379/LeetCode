#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/3sum/description/

void display_2d_vector(vector<vector<int>>& v)
{
    for(vector<int> vi: v)
    {
        for(int i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        if(nums.size() <= 2) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int a = 0, b = 0, c = 0; // 三元组（a + b + c = 0)
        int target = 0; // a的下标
        while(target <= nums.size() - 3)
        {
            // 依次以nums中的每个数nums[target]作为三元组的第一个值，剩下的两个数使用twoSum的方法来寻找
            int start = target + 1, end = nums.size() - 1;
            while(start < end)
            {
                if(nums[start] + nums[end] < -nums[target])
                    ++start;
                else if(nums[start] + nums[end] > -nums[target])
                    --end;
                else
                {
                    a = nums[target];
                    b = nums[start];
                    c = nums[end];
                    result.push_back({a, b, c});

                    //跳过相同的b与c
                    while(start < end && nums[start] == b) ++start;
                    while(end > start && nums[end] == c) --end;
                }
            }
            // 跳过相同的a
            while(target <= nums.size() - 3 && nums[target] == nums[target + 1]) ++target;
            ++target;
        }
        return result;
    }

};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    display_2d_vector(result);
    return 0;
}