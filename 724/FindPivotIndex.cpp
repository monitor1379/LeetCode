#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/find-pivot-index/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    // DP
    // Time complexity:  O(n)
    // Space complexity: O(n)
    int pivotIndex(vector<int>& nums)
    {
        vector<int> t(nums);
        for(int i = 1; i < t.size(); ++i)
            t[i] += t[i - 1];
        for(int i = 0; i < t.size(); ++i)
        {
            if(t[i] - nums[i] == t[t.size() - 1] - t[i])
                return i;
        }
        return -1;
    }
};


int main()
{
//    vector<int> nums = {1, 7, 3, 6, 5, 6};
//    vector<int> nums = {1, 3, 2, 5, 7, 2, -3};
    vector<int> nums = {-1, -1, -1, 0, 1, 1};
//    vector<int> nums = {4, 4, 4};
    display_vector(nums);

    Solution s;
    cout << s.pivotIndex(nums) << endl;
    return 0;
}
