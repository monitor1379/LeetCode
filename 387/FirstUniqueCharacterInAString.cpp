#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode.com/problems/first-unique-character-in-a-string/description/

template<typename T>
void display_2d_vector(vector<vector<T>> &v) {
    for (vector<T> vi: v) {
        for (T i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        for (char c: s) m[c]++;
        for (int i = 0; i < s.size(); ++i)
            if (m[s[i]] == 1)
                return i;
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqChar("leetcode") << endl;
    cout << s.firstUniqChar("loveleetcode") << endl;
    cout << s.firstUniqChar("") << endl;

    return 0;
}