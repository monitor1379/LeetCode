#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/1-bit-and-2-bit-characters/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int i = 0;
        while(i < bits.size())
        {
            if(i == bits.size() - 1)  return true;
            else if(i == bits.size() - 2 && bits[i] == 1)  return false;
            else if(bits[i] == 0) ++i;
            else   i += 2;
        }
    }
};

int main()
{

//    vector<int> nums = {1, 0, 0};
//    vector<int> nums = {1, 1, 1, 0};
//    vector<int> nums = {0};
//    vector<int> nums = {1, 0};
    vector<int> nums = {1, 1, 0};

    display_vector(nums);

    Solution s;
    cout << s.isOneBitCharacter(nums) << endl;
    return 0;
}
