#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/my-calendar-i/description/

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
class MyCalendar {
public:
    map<int, int> m;

    MyCalendar() {
    }
    
    /*
     * Time complexity:  O(nlogn)
     * Space complexity: O(n)
     */
    bool book(int start, int end) {
        auto next = m.lower_bound(start);
        if (next != m.end() && next->first < end) return false;
        if (next != m.begin() && start < (--next)->second) return false;
        m[start] = end;
        return true;
    }
};

int main() {
    MyCalendar obj;
    cout << obj.book(10, 20) << endl;
    cout << obj.book(15, 20) << endl;
    cout << obj.book(20, 22) << endl;
    return 0;
}