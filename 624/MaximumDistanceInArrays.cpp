#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// https://leetcode.com/problems/maximum-distance-in-arrays/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    // Approach #1: Find the two maximum numbers and two minimum numbers and their index of arrays.
    // Time complexity:  O(n)
    // Space complexity: O(1)
    int maxDistance(vector<vector<int>>& arrays)
    {
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
        int idMin1, idMin2, idMax1, idMax2;

        int k;
        for(int i = 0; i < arrays.size(); ++i)
        {
            k = *arrays[i].begin();
            if(k <= min1)
            {
                min2 = min1;
                min1 = k;

                idMin2 = idMin1;
                idMin1 = i;
            }
            else if(k <= min2)
            {
                min2 = k;
                idMin2 = i;
            }

            k = *arrays[i].rbegin();
            if(k >= max2)
            {
                max1 = max2;
                max2 = k;

                idMax1 = idMax2;
                idMax2 = i;
            }
            else if(k >= max1)
            {
                max1 = k;
                idMax1 = i;
            }
        }

        int md = 0;
        if(idMax1 != idMin1) md = max(md, abs(max1 - min1));
        if(idMax1 != idMin2) md = max(md, abs(max1 - min2));
        if(idMax2 != idMin1) md = max(md, abs(max2 - min1));
        if(idMax2 != idMin2) md = max(md, abs(max2 - min2));
        return md;
    }

};

int main()
{

    return 0;
}
