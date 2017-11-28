#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/summary-ranges/description/

void display_string_vector(vector<string> &v) {
    for (string i: v)
        cout << i << ", ";
    cout << endl;
}

template<typename T> string toString(const T& t) {
    ostringstream oss;
    oss << t;
    return oss.str();
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty()) return result;
        int k = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] - nums[i - 1] != 1)
            {
                if(k == i - 1) result.push_back(toString(nums[k]));
                else result.push_back(toString(nums[k]) + "->" + toString(nums[i - 1]));
                k = i;
            }
        }
        if(k == nums.size() - 1) result.push_back(toString(nums[k]));
        else result.push_back(toString(nums[k]) + "->" + toString(nums[nums.size() - 1]));
        return result;
    }
};

int main() {
//    vector<int> nums = {0, 1, 2, 5, 6, 8, 9, 10, 13};
    vector<int> nums = {1, 2, 3, 5};
    display_vector(nums);

    Solution s;
    vector<string> result = s.summaryRanges(nums);
    display_string_vector(result);
    return 0;
}