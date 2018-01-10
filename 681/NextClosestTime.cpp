#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/next-closest-time/description/

template<typename T>
string toString(T num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

class Solution {
private:
    int toMinutes(int h1, int h2, int m1, int m2) {
        return (h1 * 10 + h2) * 60 + m1 * 10 + m2;
    }

    int isValid(int h1, int h2, int m1, int m2) {
        return (h1 * 10 + h2) < 24 && (m1 * 10 + m2) < 60;
    }

    string toTime(int minutes) {
        string h = toString(minutes / 60);
        string m = toString(minutes % 60);
        for (int i = 0; i < 2 - h.size(); ++i) h = "0" + h;
        for (int i = 0; i < 2 - m.size(); ++i) m = "0" + m;
        return h + ":" + m;
    }

public:
    string nextClosestTime(string time) {
        vector<int> cand = {time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0'};
        int start = toMinutes(cand[0], cand[1], cand[2], cand[3]);
        int m = 10;
        int result = INT_MAX;
        for (int h1: cand) {
            m = min(m, h1);
            for (int h2: cand) {
                for (int m1: cand) {
                    for (int m2: cand) {
                        if (isValid(h1, h2, m1, m2)) {
                            int now = toMinutes(h1, h2, m1, m2);
                            if (now > start && now - start < result - start)
                                result = now;
                        }
                    }
                }
            }
        }
        if (result == INT_MAX) result = toMinutes(m, m, m, m);
        return toTime(result);
    }
};

int main() {

    Solution s;
    cout << s.nextClosestTime("19:34") << endl;
    cout << s.nextClosestTime("23:59") << endl;
    cout << s.nextClosestTime("01:32") << endl;
    return 0;
}