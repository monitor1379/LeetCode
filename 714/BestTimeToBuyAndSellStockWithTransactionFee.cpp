#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * 不是很理解这道题
     */
    int maxProfit(vector<int> &prices, int fee) {
        int cash = 0;
        int hold = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            cash = max(cash, prices[i] + hold - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    Solution s;
    cout << s.maxProfit(prices, fee) << endl;
    return 0;
}