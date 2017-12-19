#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/ransom-note/discuss/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for (char c: magazine) m[c]++;
        for (char c: ransomNote)
            if (m[c] == 0)
                return false;
            else
                m[c]--;
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConstruct("a", "b") << endl;
    cout << s.canConstruct("aa", "ab") << endl;
    cout << s.canConstruct("aa", "aab") << endl;

    return 0;
}