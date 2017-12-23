#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/student-attendance-record-i/description/

class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0, cntL = 0;
        for (char c: s) {
            if (c == 'L') cntL++;
            else cntL = 0;
            if (c == 'A') cntA++;
            if (cntA == 2 || cntL == 3)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    cout << s.checkRecord("PPALLL") << endl;

    return 0;
}