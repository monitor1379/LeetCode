#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/reshape-the-matrix/description/

void display_2d_vector(vector<vector<int>> v)
{
    for(vector<int> vi : v)
    {
        for(int i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

class Solution
{
public:
    // One loop
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
        int R = nums.size(), C = nums[0].size();
        if(R * C != r * c)
            return nums;
        vector<vector<int>> m(r, vector<int>(c));
        for(int idx = 0; idx < R * C; ++idx)
        {
            m[idx / c][idx % c] = nums[idx / C][idx % C];
        }
        return m;
    }
};

int main()
{
    vector<vector<int>> nums = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    display_2d_vector(nums);

    Solution s;
    display_2d_vector(s.matrixReshape(nums, 5, 3));
    return 0;
}
