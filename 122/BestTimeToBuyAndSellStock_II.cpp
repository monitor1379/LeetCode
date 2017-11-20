#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution
{
public:
    // greedy
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        for(int i = prices.size() - 1; i > 0; --i)
        {
            if(prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

int main()
{
    vector<int> prices = {1, 2, 3, 4};
    display_vector(prices);
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}
