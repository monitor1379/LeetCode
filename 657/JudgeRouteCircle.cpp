#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/judge-route-circle/description/

class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> m;
        for (char c: moves) ++m[c];
        return m['U'] == m['D'] && m['L'] == m['R'];
    }
};

int main() {
    Solution s;
    cout << s.judgeCircle("UUDD") << endl;
    cout << s.judgeCircle("") << endl;

    return 0;
}