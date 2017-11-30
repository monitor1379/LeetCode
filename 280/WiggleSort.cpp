#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/wiggle-sort/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach #1: Sort and swap.
     * 1. sort.
     * 2. swap:
     *     [0  1  2   3  4   5  6 ...  ]
     *         ↑  ↑   ↑  ↑   ↑  ↑
     *         swap   swap   swap
     *
     * Time complexity:  O(nlogn)
     * Space complexity: O(1)
     */
    void wiggleSort2(vector<int>& nums) {
        if(nums.empty()) return ;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size() - 1; i += 2)
            swap(nums[i], nums[i + 1]);
    }

    /*
     * Approach #2: One-pass swap.
     *
     *
     * TODO
     * TODO
     * TODO
     * TODO
     */
    void wiggleSort(vector<int>& nums) {
        // TODO
    }

};

int main() {
    vector<int> nums = {1, 2, 4};
    display_vector(nums);
    Solution s;
    s.wiggleSort(nums);
    display_vector(nums);
    return 0;
}