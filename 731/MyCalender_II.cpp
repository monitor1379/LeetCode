#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/my-calendar-ii/description/

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

class MyCalendarTwo {
private:
    vector<vector<int>> calender;
    vector<vector<int>> overlap;
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        for (vector<int> event: overlap)
            if (event[0] < end && start < event[1])
                return false;
        for (vector<int> event: calender)
            if (event[0] < end && start < event[1])
                overlap.push_back({max(event[0], start), min(event[1], end)});
        calender.push_back({start, end});
        return true;
    }
};


int main() {
    MyCalendarTwo obj;

    cout << obj.book(10, 20) << endl;
    cout << obj.book(50, 60) << endl;
    cout << obj.book(10, 40) << endl;
    cout << obj.book(5, 15) << endl;
    cout << obj.book(5, 10) << endl;
    cout << obj.book(25, 55) << endl;
    return 0;
}