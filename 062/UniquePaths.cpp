#include <iostream>

using namespace std;

//https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    /*
     * Approach #1: 2D DP
     * dp[0][0] = 1
     * dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
     *
     * Time complexity:  O(m * n)
     * Space complexity: O(min(m, n))
     */
    int uniquePaths1(int m, int n) {
        if (m < 1 || n < 1) return 0;
        if (m < n) swap(m, n);
        vector<int> states(n, 1);
        for (int i = 1; i <= m - 1; ++i)
            for (int j = n - 2; j >= 0; --j)
                states[j] += states[j + 1];
        return states[0];
    }

    /*
     * Approach #2: Math.
     *
     * 由题意可知，在一个m行n列的地图中，从起点到终点一共需要走m+n-2步，其中m-1步为向下走，n-1步向右走，
     * 设向下走为D，向右走为R，那么一条路可表示为一个m+n-2长的序列，其中包括m-1个D与n-1个R，例如：
     * 在一个3x5的地图中，有：
     *     D R D R R R
     * 为了方便计算，此处处理：m = m - 1, n = n - 1;
     * 所以该问题可转换为，由m个D与n个R可组成多少个不同的字符串。
     * 进一步地，根据排列组合，上问题实际上等价于组合问题：给定m+n个位置，挑m个分给D，剩下的分给R，一共有$C^m_{m+n}$种分法，
     * 答案为：C^m_{m+n} = A^m_{m+n} / m! = (m+n)! / (m+n - m)! / m! = (m+n)!/(m!n!)
     *
     */
    int uniquePaths2(int m, int n) {
        if(m < 1 || n < 1) return 0;
        double result = 1;
        if(m > n) swap(m, n);
        --m;
        --n;
        for(int i = 1; i <= m; ++i)
            result = result * (i + n) / i ;
        return (int)result;
    }

};


int main() {
    Solution s;
    cout << s.uniquePaths(4, 6) << endl;
    return 0;
}