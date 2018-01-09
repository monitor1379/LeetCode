#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/repeated-string-match/description/

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
    /*
     * Approach: Ad-Hoc.
     *
     * Time complexity:  O(len(A) * len(B))
     * Space complexity: O(1)
     *
     * 基本思想：
     * 依次判断B是否是A*k的子串，k从1开始增加。子串搜索采用KMP等方法进行匹配。
     *
     *
     */
    int repeatedStringMatch2(string A, string B) {
        if (B.empty()) return -1;
        int cnt;
        for (int start = 0; start < A.size(); ++start) {
            if (A[start] == B[0]) {
                int i = start, j = 0;
                cnt = 1;
                while (j < B.size() && A[i] == B[j]) {
                    ++i;
                    ++j;
                    if (i >= A.size() && j < B.size()) {
                        ++cnt;
                        i = 0;
                    }
                }
                if (j == B.size()) return cnt;
            }
        }
        return -1;
    }

    /*
     * Approach: Ad-Hoc.
     *
     * Time complexity:  O(len(A) * len(B))
     * Space complexity: O(len(A) + len(B))
     */
    int repeatedStringMatch3(string A, string B) {
        int cnt = 1;
        string t = A;
        while (t.size() < B.size()) {
            t.append(A);
            cnt++;
        }
        if (t.find(B) != -1) return cnt;
        t.append(A);
        if (t.find(B) != -1) return cnt + 1;
        return -1;
    }

    bool check(int start, string A, string B) {
        for (int i = 0; i < B.size(); ++i)
            if (A[(start + i) % A.size()] != B[i])
                return false;
        return true;
    }

    int getCode(char c) {
        return c - 'a' + 1;
    }

    /*
     * Approach: Rabin-Karp (Rolling Hash).
     *
     * Time complexity:  O(len(A) + len(B))
     * Space complexity: O(1)
     *
     *
     */
    int repeatedStringMatch(string A, string B) {
        int prime = 17, mod = 1000000000;
        int hashB = 0, power = 1;


        for (int i = 0; i < B.size(); ++i) {
            hashB += power * getCode(B[i]);
            hashB %= mod;
            power = (power * prime) % mod;
        }
        cout << B << ": " << hashB << endl;

        int hashA = 0;
        power = 1;
        for (int i = 0; i < B.size(); ++i) {
            hashA += power * getCode(A[i % A.size()]);
            hashA %= mod;
            power = (power * prime) % mod;
        }
        power /= prime;

        // TODO p_inv
        for (int i = B.size(); i < A.size() + B.size(); ++i) {
            cout << "=========" << endl;
            for (int j = i - B.size(); j < i; ++j)
                cout << A[j % A.size()];
            cout << ": " << hashA << endl;
            if (hashA == hashB && check(i - B.size(), A, B))
                return (i - 1) / A.size() + 1;
            cout << "minus:" << A[i - B.size()] << ", add:" << A[i % A.size()] << endl;
            cout << hashA << endl;
            hashA -= getCode(A[i - B.size()]);
            cout << hashA << endl;
            hashA /= prime; // TODO
            cout << hashA << endl;
            hashA += (power * getCode(A[i % A.size()])) % mod;
            cout << hashA << endl;
        }

        int result = 0;
        return result;
    }
};

int main() {
    string a = "abcd";
    string b = "cdabcda";


    Solution s;
    cout << s.repeatedStringMatch(a, b) << endl;
    return 0;
}