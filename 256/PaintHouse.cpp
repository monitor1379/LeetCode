#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/paint-house/description/

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;
        for(int i = 1; i < n; ++i) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }
        return min(min(costs[n-1][0], costs[n-1][1]), costs[n-1][2]);
    }
};

int main() {
    vector<vector<int>> costs = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}};

    Solution s;
    cout << s.minCost(costs) << endl;
    return 0;
}