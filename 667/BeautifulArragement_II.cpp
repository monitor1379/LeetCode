#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/beautiful-arrangement-ii/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: Construction
     *
     * Given n and k, construct an array:
     *
     *     [1, n, 2, n-1, ... , i, n-(i-1), i+1, i+2, i+3, ..., n]
     *      n-1|n-2|n-3| .....  |n-k+1|   |1|  |1|  |1|   
     */
    vector<int> constructArray(int n, int k) {
        if (n <= 0 || k <= 0) return {};
        vector<int> result;
        int low = 1, high = n;
        // 使用k个数，构建k-1个不同的差
        for (int i = 0; i < k; ++i) {
            if (i % 2 == 0) result.push_back(low++);
            else result.push_back(high--);
        }
        // 构造最后一个为1的差
        if (k % 2 == 1)
            for (int i = low; i <= high; ++i) result.push_back(i);
        else
            for (int i = high; i >= low; --i) result.push_back(i);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> result = s.constructArray(2, 1);
    display_vector(result);
    return 0;
}