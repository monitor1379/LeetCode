#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

void display_vector(vector<int> v)
{
    for(int i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    // 该题类似Two Sum，只不过是寻找两数之差。
    // Time complexity:  O(n)
    // Space complexity: O(n)
    int findPairs(vector<int>& nums, int k)
    {
        if(k < 0) return 0;
        int n = 0;
        map<int, int> m;
        for(int i: nums)
            m[i] += 1;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
//            cout << it->first << ", " << it->second << endl;
            if(k != 0)
            {
               if(m.find(it->first + k) != m.end())
                    ++n;
            }
            else
            {
                if(m[it->first] >= 2)
                    ++n;
            }

        }

        return n;
    }
};

int main()
{
//    vector<int> nums = {1, 4, 3, 4, 5, 4, 7};
    vector<int> nums = {1, 2, 3, 4, 5};
    display_vector(nums);

    Solution s;
    cout << s.findPairs(nums, -1) << endl;
    return 0;
}
