#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// https://leetcode.com/problems/maximum-product-of-three-numbers/description/

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

class Solution
{
public:
    // Time complexity:  O(n)
    // Space complexity: O(1)
    int maximumProduct(vector<int>& nums)
    {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for(int i: nums)
        {
            if(i <= min1)
            {
                min2 = min1;
                min1 = i;
            }
            else if (i <= min2)
            {
                min2 = i;
            }

            if(i >= max3)
            {
                max1 = max2;
                max2 = max3;
                max3 = i;
            }
            else if(i >= max2)
            {
                max1 = max2;
                max2 = i;
            }
            else if(i >= max1)
            {
                max1 = i;
            }
        }
        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 4, 4, 4};
    display_vector(nums);
    Solution s;
    cout << s.maximumProduct(nums) << endl;
    return 0;
}
