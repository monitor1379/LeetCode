#include <iostream>
#include <vector>
#include <set>

using namespace std;

// https://leetcode.com/problems/third-maximum-number/description/


class Solution
{
public:
    int thirdMax(vector<int>& nums)
    {
        set<int> s;
        for(int i: nums) s.insert(i);
        if(s.size() < 3)  return *(s.rbegin());
        else return *++++s.rbegin();
    }
};

int main()
{

//    vector<int> nums = {1, 2, 3};
//    vector<int> nums = {1, 1, 1, 3};
//    vector<int> nums = {0};
//    vector<int> nums = {1, 0};
    vector<int> nums = {1, 2, 3, 4};

    display_vector(nums);

    Solution s;
    cout << s.thirdMax(nums) << endl;
    return 0;
}
