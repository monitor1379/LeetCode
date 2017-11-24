#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/container-with-most-water/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    // Two pointers.
    // Time complexity:  O(n)
    // Space complexity: O(1)
    int maxArea(vector<int>& height)
    {
        int area = 0;
        int i = 0, j = height.size() - 1;
        while(i < j)
        {
            area = max(area, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j]) ++i;
            else --j;
        }
        return area;
    }
};


int main()
{
//    vector<int> height = {1, 7, 3, 6, 5, 6};
//    vector<int> height = {1,8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height = {2, 3, 2};
    display_vector(height);

    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}
