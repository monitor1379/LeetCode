#include <iostream>
#include <vector>

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
     * Approach2: Ad-Hoc.
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
     * Approach3: Ad-Hoc.
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
     * 通过计算两个字符串的hash值，比较其hash值是否相等，来判断两个字符串是否匹配。
     * 适当构造hash函数，每次计算复杂度可为O(1)。
     *
     * 假设字符串A为"abcde"，给定质数p，计算"abcd"的hash值：
     * hash("abcd") = p^3*'a' + p^2*'b' + p^1*'c' + p^0*'d'
     *
     * 则"bcde"的hash值可通过hash("abcd")递推：
     * hash("bcde") = (hash("abcd") - p^3*'a') * p + 'e'
     *
     * 由于存在碰撞，因此两个字符串hash值相同时，检查一遍是否完全相等。
     *
     */
    int repeatedStringMatch(string A, string B) {
        int prime = 17;

        // 计算B的hash值
        long long hashB = 0;
        long long power = 1;
        for (int i = B.size() - 1; i >= 0; --i) {
            hashB += power * getCode(B[i]);
            power = (power * prime);
        }

        // 计算A的hash值
        long long hashA = 0;
        power = 1;
        for (int i = B.size() - 1; i >= 0; --i) {
            hashA += power * getCode(A[i % A.size()]);
            power = (power * prime);
        }
        power /= prime;

        // 递推计算A拼成的字符串的hash值
        for (int i = B.size(); i < A.size() + B.size(); ++i) {
            if (hashA == hashB && check(i - B.size(), A, B))
                return (i - 1) / A.size() + 1;
            hashA -= power * getCode(A[i - B.size()]);
            hashA *= prime;
            hashA += getCode(A[i % A.size()]);
        }
        return -1;
    }
};

int main() {
//    string a = "abcd";
//    string b = "cdabcdab";
    string a = "a";
    string b = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    Solution s;
    cout << s.repeatedStringMatch(a, b) << endl;
    return 0;
}