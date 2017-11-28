#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/merge-intervals/description/

// Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

void display_interval(vector<Interval> v) {
    for (Interval i: v)
        cout << "[" << i.start << ", " << i.end << "], ";
    cout << endl;
}

bool IntervalCompareImpl(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    // TODO 尝试用并查集

    // Approach #1: Using sorting.
    // Time complexity:  O(nlogn)
    // Space complexity: O(1)
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end(), IntervalCompareImpl);
        vector<Interval> result;
        result.push_back(intervals[0]);
        int k = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            // 如果overlap
            if(result[k].end >= intervals[i].start)
                result[k].end = max(result[k].end, intervals[i].end);
            else
            {
                result.push_back(intervals[i]);
                ++k;
            }
        }
        return result;
    }
};

int main() {
    vector<Interval> intervals = {Interval(1, 9), Interval(2, 5), Interval(19, 20), Interval(10, 11),
                                  Interval(12, 20), Interval(0, 3), Interval(0, 1), Interval(0, 2)};
    display_interval(intervals);
    Solution s;
    vector<Interval> result = s.merge(intervals);
    display_interval(result);
    return 0;
}