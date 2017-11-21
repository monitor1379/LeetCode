#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

class Solution
{
public:

    /*
    The basic idea is that we iterate through the input array and
    mark elements as negative using nums[nums[i] -1] = -nums[nums[i]-1].
    In this way all the numbers that we have seen will be marked as negative.
    In the second iteration, if a value is not marked as negative,
    it implies we have never seen that index before, so just add it to the return list.

    input:  [1, 3, 3, 3, 4, 4]
    marked: [-1, 3, -3, -3, 4, 4]
    position of positive number: [1, 4, 5]
    result: [2, 5, 6]

    Time complexity:  O(n)
    Space complexity: O(1)
    */
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] > 0)
                result.push_back(i + 1);
        return result;
    }

    // Time complexity:  O(nlogn)
    // Space complexity: O(1)
    vector<int> findDisappearedNumbers1(vector<int>& nums)
    {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int j = 1;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] < j)
            {
                ++i;
            }
            else if(nums[i] > j)
            {
                result.push_back(j);
                ++j;
            }
            else
            {
                ++i;
                ++j;
            }
        }
        for(; j <= nums.size(); ++j)
            result.push_back(j);
        return result;
    }
};

int main()
{
//    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> nums = {1, 3, 3, 3, 4, 4};
    Solution s;
    display_vector(s.findDisappearedNumbers(nums));
    return 0;
}
