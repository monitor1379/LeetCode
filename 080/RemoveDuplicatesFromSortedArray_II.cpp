#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int j = 0;
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[j] == nums[i]) {
                ++cnt;
                if (cnt == 2) {
                    ++j;
                    nums[j] = nums[j - 1];
                }
            } else {
                ++j;
                nums[j] = nums[i];
                cnt = 1;
            }
        }
        return j + 1;
    }
};


int main() {
    vector<int> nums = {0, 0, 0, 1, 1, 1, 2, 3, 3, 3};
//    vector<int> nums = {1, 1, 2};
    display_vector(nums);
    
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}