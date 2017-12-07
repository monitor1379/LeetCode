#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/teemo-attacking/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: 计算每两个时间点之间的中毒时间。
     */
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int result = 0;
        for (int i = 1; i < timeSeries.size(); ++i)
            result += min(timeSeries[i] - timeSeries[i - 1], duration);
        return result + duration;
    }
};

int main() {
    vector<int> timeSeries = {1};
    int duration = 1;
    Solution s;
    cout << s.findPoisonedDuration(timeSeries, duration) << endl;
    return 0;
}