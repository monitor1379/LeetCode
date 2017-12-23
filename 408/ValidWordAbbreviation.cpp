#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/valid-word-abbreviation/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

int stringToInt(string s) {
    stringstream ss;
    ss << s;
    int r;
    ss >> r;
    return r;
}

bool isLetter(char c) {
    return c >= 'a' && c <= 'z';
}


class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        string t;
        while (j < abbr.size()) {
            if (isLetter(abbr[j])) {
                if (t.empty()) i += 0;
                else if (t[0] == '0') return false;
                else i += stringToInt(t);
                if (i >= word.size() || word[i] != abbr[j]) return false;
                ++i;
                ++j;
                t = "";
            } else {
                t += abbr[j];
                ++j;
            }
        }
        if (t.empty()) return i == word.size();
        else if (t[0] == '0') return false;
        else return word.size() - i == stringToInt(t);
    }
};

int main() {
    Solution s;
    cout << s.validWordAbbreviation("internationalization", "i12iz4n") << endl;
    cout << s.validWordAbbreviation("apple", "a2e") << endl;
    cout << s.validWordAbbreviation("word", "3d") << endl;
    cout << s.validWordAbbreviation("word", "4") << endl;
    cout << s.validWordAbbreviation("word", "3") << endl;
    cout << s.validWordAbbreviation("word", "") << endl;
    cout << s.validWordAbbreviation("", "3") << endl;
    cout << s.validWordAbbreviation("", "") << endl;
    cout << s.validWordAbbreviation("a", "01") << endl;
    return 0;
}