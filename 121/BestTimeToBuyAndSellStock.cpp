#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrice = INT_MAX;
        int profit = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < minPrice)
                minPrice = prices[i];
            else if(prices[i] - minPrice > profit)
                profit = prices[i] - minPrice;
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
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    display_vector(nums);
    Solution s;
    cout << s.maxProfit(nums) << endl;
    return 0;
}
