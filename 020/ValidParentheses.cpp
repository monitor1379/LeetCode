#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> m{{')', '('},
                          {'}', '{'},
                          {']', '['}};
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty() || st.top() != m[c])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {

    Solution s;
    cout << s.isValid("[{()[]]}]") << endl;
    cout << s.isValid("]") << endl;
    cout << s.isValid("[") << endl;
    cout << s.isValid("") << endl;
    return 0;
}