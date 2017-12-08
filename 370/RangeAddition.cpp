#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/range-addition/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach #1: Naive traversal.
     *
     * Time complexity:  O(length * updates.size())
     */
    vector<int> getModifiedArray1(int length, vector<vector<int>> &updates) {
        vector<int> result(length, 0);
        for (vector<int> update: updates)
            for (int i = update[0]; i <= update[1]; ++i)
                result[i] += update[2];
        return result;
    }

    /*
     * Approach #2: Range Caching
     *
     *
     * 举个例子，如果长度是5，某次update为[1, 2, 2]，则
     * [0, 2, 0, -2, 0]
     * 使用累积和进行更新
     * [0, 2, 2, 0, 0]
     *
     * Time complexity:  O(length)
     *
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> result(length, 0);
        for (vector<int> update: updates) {
            result[update[0]] += update[2];
            if (update[1] < length - 1)
                result[update[1] + 1] -= update[2];
        }
        for (int i = 1; i < result.size(); ++i)
            result[i] += result[i - 1];
        return result;
    }
};

int main() {
    int length = 5;
    vector<vector<int>> updates = {{1, 3, 2},
                                   {2, 4, 3},
                                   {0, 2, -2}};
    Solution s;
    vector<int> result = s.getModifiedArray(length, updates);
    display_vector(result);
    return 0;
}