#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/merge-sorted-array/description/

class Solution
{
public:
    // 注意边界条件
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0)
        {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        for(; j >=0; --j)
            nums1[j] = nums2[j];


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
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};

    display_vector(nums1);
    display_vector(nums2);

    Solution s;
    s.merge(nums1, 0, nums2, 1);
    display_vector(nums1);
    return 0;
}
