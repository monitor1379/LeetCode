#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/missing-number/description/

class Solution
{
public:
    //Bit manipulation
    /*
    Because we know that nums contains n n numbers and that
    it is missing exactly one number on the range [0..n-1],
    we know that n definitely replaces the missing number in nums.

    Therefore, if we initialize an integer to n and XOR it with
    every index and value, we will be left with the missing number.

    Mathematical Proof:
    Rule 1. v XOR v = 0
    Rule 2. u XOR 0 = u

    given a array [0, ..., n], we get:
        (0 XOR 0) XOR (1 XOR 1) XOR ... XOR (k XOR k) XOR ... XOR (n XOR x)
      = 0 XOR 0 XOR ... XOR 0
      = 0

    if the missing number is k, then:
        (0 XOR 0) XOR (1 XOR 1) XOR ... XOR k XOR ... XOR (n XOR x)
      = 0 XOR 0 XOR ... XOR k XOR ... XOR 0
      = k XOR 0
      = k

    so if we get k.
    */
    int missingNumber(vector<int>& nums)
    {
        int k = nums.size();
        for(int i = 0; i < nums.size(); ++i)
            k = k ^ i ^ nums[i];
        return k;
    }

    // Guass' Formula
    int missingNumber2(vector<int>& nums)
    {
        int n = nums.size();
        int sum = (n + 1) * n / 2;
        for(int i: nums)
            sum -= i;
        return sum;
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
    vector<int> nums = {2, 4, 3, 0};
    Solution s;
    cout << s.missingNumber(nums) << endl;
    return 0;
}
