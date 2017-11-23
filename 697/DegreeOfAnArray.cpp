#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/degree-of-an-array/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    // Time complexity:  O(n)
    // Space complexity: O(n)
    int findShortestSubArray(vector<int>& nums)
    {
        map<int, vector<int>> m;
        int maxDegree = 1;
        int minLength = 50001;
        vector<int> numsHasMaxDegree;
        for(int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]].push_back(i);
            if(m[nums[i]].size() == maxDegree)
                numsHasMaxDegree.push_back(nums[i]);
            else if(m[nums[i]].size() > maxDegree)
            {
                numsHasMaxDegree.clear();
                numsHasMaxDegree.push_back(nums[i]);
                maxDegree = m[nums[i]].size();
            }
        }
        for(int k: numsHasMaxDegree)
        {
            pair<vector<int>::iterator, vector<int>::iterator> minAndMaxIndex = minmax_element(m[k].begin(), m[k].end());
            minLength = min(minLength, *minAndMaxIndex.second - *minAndMaxIndex.first + 1);
        }
        return minLength;
    }
};

int main()
{
//    vector<int> nums = {1, 2, 2, 3, 1, 1, 1, 2, 2};
//    vector<int> nums = {1};
//    vector<int> nums = {1, 1, 1, 1};
    vector<int> nums = {1, 2, 3, 4};

    display_vector(nums);

    Solution s;
    cout << s.findShortestSubArray(nums) << endl;
    return 0;
}
