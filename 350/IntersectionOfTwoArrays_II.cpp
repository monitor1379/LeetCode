#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

template<typename T>
void display_2d_vector(vector<vector<T>> &v) {
    for (vector<T> vi: v) {
        for (T i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}


class Solution {
public:
    /*
     * Approach: Hash Table.
     *
     * Time complexity:  O(n1 + n2)
     * Space complexity: O(n1)
     *
     */
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> m;
        vector<int> result;
        for (int i: nums1) m[i]++;
        for (int i: nums2)
            if (m[i]-- > 0)
                result.push_back(i);
        return result;
    }

    /*
     * 1. What if the given array already sorted?
     * How would you optimize your algorithm?
     *
     * Approach: Two pointers.
     *
     * Time complexity:  O(min(n1, n2))
     * Space complexity: O(1)
     *
     */

    vector<int> intersect1(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ++i, ++j) {
            if (nums1[i] == nums2[j]) result.push_back(nums1[i]);
            else if (nums1[i] < nums2[j]) --j;
            else --i;
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution s;
    vector<int> result = s.intersect(nums1, nums2);
    display_vector(result);
    return 0;
}