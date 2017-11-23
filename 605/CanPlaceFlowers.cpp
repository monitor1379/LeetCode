#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/can-place-flowers/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int nFlowers = 0;
        int i = 0;
        while(i < flowerbed.size())
        {
            if(flowerbed[i] == 1)
                i += 2;
            else
            {
                int k = 0;
                if(i > 0) k += flowerbed[i - 1];
                if(i < flowerbed.size() - 1) k += flowerbed[i + 1];
                if(k == 0)
                {
                    ++nFlowers;
                    if(nFlowers >= n) return true;
                    i += 2;
                }
                else
                {
                    ++i;
                }
            }
        }
        return nFlowers >= n ? true : false;
    }
};

int main()
{
//    vector<int> nums = {1, 0, 0, 0, 0};
    vector<int> nums = {1, 0, 0, 0, 0, 1};
//    vector<int> nums = {1};
//    vector<int> nums = {0};

    display_vector(nums);

    Solution s;
    cout << s.canPlaceFlowers(nums, 1) << endl;
    return 0;
}
