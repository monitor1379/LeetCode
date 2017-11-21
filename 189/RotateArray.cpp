#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/rotate-array/description/

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

class Solution
{
public:
    // Approach #1: A normal way.
    void rotate1(vector<int>& nums, int k)
    {
        k = k % nums.size();
        vector<int> tmp(nums);
        for(int i = 0; i < k; ++i)
            nums[i] = tmp[nums.size() - k + i];
        for(int i = k; i < nums.size(); ++i)
            nums[i] = tmp[i - k];
    }

    // Approach #2: Cyclic Replacements.
    void rotate2(vector<int>& nums, int k)
    {
        k %= nums.size();
        int cnt = 0;
        int start = 0;
        for(int start = 0; cnt < nums.size(); ++start)
        {
            int i = start;
            int j;
            int t = nums[i];
            do
            {
                j = (i + k) % nums.size();
                swap(nums[j], t);
                i = j;
                ++cnt;
            } while(i != start && cnt < nums.size());
        }
    }

    // Approach #3: Using reverse.
    void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();
        for(int i = 0; i < nums.size() / 2; ++i)
            swap(nums[i], nums[nums.size() - i - 1]);

        for(int i = 0; i < k / 2; ++i)
            swap(nums[i], nums[k - i - 1]);

        for(int i = k; i < int(nums.size() + k) / 2; ++i)
            swap(nums[i], nums[nums.size() + k - i - 1]);

    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution s;
    s.rotate(nums, k);

    display_vector(nums);
    return 0;
}
