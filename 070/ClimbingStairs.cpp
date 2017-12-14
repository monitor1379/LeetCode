#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/climbing-stairs/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: DP with memory.
     */
    int climbStairs(int n) {
        vector<int> m(n + 1, -1);
        return climb(n, m);
    }

    int climb(int n, vector<int> &m) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        else {
            if (m[n] == -1)
                m[n] = climb(n - 1, m) + climb(n - 2, m);
            return m[n];
        }
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(44) << endl;
    return 0;
}