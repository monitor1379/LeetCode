#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/string-compression/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

template<typename T>
string toString(T num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

class Solution {
public:
    int compress(vector<char> &chars) {
        char curChar = chars[0];
        int cnt = 1, j = 0;
        for (int i = 1; i <= chars.size(); ++i) {
            if (i == chars.size() || curChar != chars[i]) {
                chars[j] = curChar;
                ++j;
                if (cnt > 1) {
                    string t = toString(cnt);
                    for (int k = 0; k < t.size(); ++k)
                        chars[j++] = t[k];
                }
                cnt = 1;
                if (i < chars.size()) curChar = chars[i];
            } else cnt++;
        }
        return j;
    }
};

int main() {
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> chars2 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

    Solution s;
    cout << s.compress(chars1) << endl;
    display_vector(chars1);

    cout << s.compress(chars2) << endl;
    display_vector(chars2);
    return 0;
}