#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: Integral Image.
     *
     * Time complexity:  O(n^2)
     * Space complexity: O(n)
     *
     */
    int subarraySum(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        vector<int> s(nums);
        for (int i = 1; i < nums.size(); ++i)
            s[i] += s[i - 1];
        int result = 0, t;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if ((i == 0 && s[j] == k) || (i != 0 && s[j] - s[i - 1] == k))
                    ++result;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    cout << s.subarraySum(nums, 3) << endl;
    return 0;
}