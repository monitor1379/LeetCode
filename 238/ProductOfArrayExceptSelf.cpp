#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/product-of-array-except-self/description/

void display_vector(vector<int>& v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    // Request: solve it without division and in O(n)
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> result(nums);
        result[0] = 1;
        for(int i = 1; i < result.size(); ++i) result[i] = result[i - 1] * nums[i - 1];
        int right = 1;
        for(int i = result.size() - 1; i >= 0; --i)
        {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};

int main()
{
//    vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {3, 5, 4};
    Solution s;
    vector<int> result = s.productExceptSelf(nums);
    display_vector(result);
    return 0;
}