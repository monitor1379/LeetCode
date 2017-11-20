#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/array-partition-i/description/


class Solution {
public:
    /*
    We need to form the pairings of the array's elements such that the overall sum
    of the minimum out of such pairings is maximum. Thus, we can look at the operation
    of choosing the minimum out of the pairing, say (a, b)(a,b) as incurring a loss
    of a - ba−b(if a> ba>b), in the maximum sum possible.

    The total sum will now be maximum if the overall loss incurred from such pairings
    is minimized. This minimization of loss in every pairing is possible only if the
    numbers chosen for the pairings lie closer to each other than to the other elements
    of the array.

    Taking this into consideration, we can sort the elements of the given array and form
    the pairings of the elements directly in the sorted order. This will lead to the
    pairings of elements with minimum difference between them leading to the maximization
    of the required sum.
    */
    int arrayPairSum(vector<int>& nums) {
        int s = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 2)
            s += nums[i];
        return s;
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
    vector<int> nums = {1, 4, 3, 2};
    display_vector(nums);
    sort(nums.begin(), nums.end());
    display_vector(nums);
    Solution s;
    cout << s.arrayPairSum(nums) << endl;
    return 0;
}
