#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// https://leetcode.com/problems/license-key-formatting/description/

class Solution {
public:
    /*
     * Approach: reversely building new string.
     *
     * Time complexity:  O(n)
     * Space complexity: O(n)  non in-place
     *
     */
    string licenseKeyFormatting(string S, int K) {
        string t;
        for (int i = S.size() - 1; i >= 0; --i) {
            if (S[i] != '-') {
//                t += (S[i] >= 'a' && S[i] <= 'z') ? (S[i] - 'a' + 'A') : S[i];
                t += toupper(S[i]);
                if (t.size() % (K + 1) == K) t += "-";
            }
        }
        if (t.back() == '-') t.erase(t.size() - 1, 1);
        reverse(t.begin(), t.end());
        return t;
    }
};

int main() {
    string S = "5F3Z-2e-9-w";
    string S2 = "2-5g-3-J";
    string S3 = "--a-a-a-a--";
    Solution s;
    cout << s.licenseKeyFormatting(S, 4) << endl;
    cout << s.licenseKeyFormatting(S2, 2) << endl;
    cout << s.licenseKeyFormatting(S3, 2) << endl;
    return 0;
}