#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/number-of-segments-in-a-string/description/

class Solution {
public:
    int countSegments(string s) {
        int result = 0;
        int i = 0;
        bool hasPrevWord = false;
        while (i < s.size()) {
            if (s[i] != ' ')
                hasPrevWord = true;
            else {
                if (hasPrevWord) {
                    ++result;
                    hasPrevWord = false;
                }
            }
            ++i;
        }
        return result + (hasPrevWord ? 1 : 0);
    }
};

int main() {
    Solution s;
    cout << s.countSegments("Hello, my name is John.") << endl;
    cout << s.countSegments("abc abc") << endl;
    cout << s.countSegments(" abc abc") << endl;
    cout << s.countSegments("abc abc  ") << endl;
    cout << s.countSegments("  abc abc  ") << endl;
    cout << s.countSegments("  ") << endl;
    cout << s.countSegments("") << endl;
    return 0;
}