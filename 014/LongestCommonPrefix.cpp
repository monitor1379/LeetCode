#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        string lcp = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j;
            for (j = 0; j < min(lcp.size(), strs[i].size()); ++j) {
                if (lcp[j] != strs[i][j])
                    break;
            }
            lcp = lcp.substr(0, j);
        }
        return lcp;
    }
};

int main() {
    vector<string> strs = {"1123", "233", "1"};
    cout << "\"" << strs[0].substr(0, 0) << "\"" << endl;
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}