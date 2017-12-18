#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/implement-strstr/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: KMP algorithm.
     *
     * https://www.cnblogs.com/zhangtianq/p/5839909.html
     *
     * Time complexity:  O(haystack.size())
     * Space complexity: O(needle.size())
     *
     */
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        if (needle.empty()) return 0; //坑人
        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        // 注意，j = -1时，(j < needle.size())的结果为false，所以要将size_t类型强转为int类型
        while (i < haystack.size() && j < int(needle.size())) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        if (j == needle.size())
            return i - j;
        else
            return -1;
    }

    vector<int> getNext(string pattern) {
        vector<int> next(pattern.size(), 0);
        next[0] = -1;
        int k = -1, j = 0;
        while (j < next.size() - 1) {
            if (k == -1 || pattern[k] == pattern[j]) {
                next[++j] = ++k;
            } else
                k = next[k];
        }
        return next;
    }
};

int main() {
    Solution s;
    cout << s.strStr("hello", "ll") << endl;

    return 0;
}