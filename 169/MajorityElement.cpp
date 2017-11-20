#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/majority-element/description/

class Solution
{
public:
    // 普通做法，哈希表：O(n)时间，O(n)空间
    // LeetCode:19ms
    int majorityElement(vector<int>& nums)
    {
        map<int, int> m;
        int majority = 0;
        int majority_count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            ++m[nums[i]];
            if(m[nums[i]] > majority_count)
            {
                majority = nums[i];
                majority_count = m[nums[i]];
            }
        }
        return majority;
    }

    // Moore's Voting Algorithm：O(n)时间，O(1)空间
    // 由于重复频率超过floor(n/2)的数字只有一个，等价于与其余数字出现频率的差大于零
    // 当遍历整个数组时，使用变量candidate记录当前重复次数最多的数，cnt计算candidate重复多余的次数
    // 注意：该算法适用的一个前提就是majorityElement的出现次数大于loor(n/2)。例如：{1, 2, 3, 2, 4}中就无majorityElement。
    // LeetCode:16ms
    int majorityElement2(vector<int>& nums)
    {
        int candidate = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == candidate)
                ++cnt;
            else if(cnt == 0)
            {
                candidate = nums[i];
                ++cnt;
            }
            else
                cnt--;
        }
        return candidate;
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
    vector<int> nums = {2, 3, 2, 1, 2, 4, 2};
    display_vector(nums);
    Solution s;
    cout << s.majorityElement2(nums) << endl;
    return 0;
}
