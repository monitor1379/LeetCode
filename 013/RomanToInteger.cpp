#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m{{'I', 1},
                         {'V', 5},
                         {'X', 10},
                         {'L', 50},
                         {'C', 100},
                         {'D', 500},
                         {'M', 1000}};

        int sum = m[s.back()];
        for (int i = s.size() - 2; i >= 0; --i) {
            if (m[s[i]] >= m[s[i + 1]])
                sum += m[s[i]];
            else
                sum -= m[s[i]];
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("XII") << endl;
    cout << s.romanToInt("IV") << endl;
    return 0;
}