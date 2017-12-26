#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/count-primes/description/

class Solution {
public:
    int countPrimes(int n) {
        vector<int> m(n, 1);
        int result = 0;
        for (int i = 2; i < n; ++i) {
            if (m[i] == 1) ++result;
            // 慢
            // for (int j = 2; i * j < n; ++j)m[i * j] = 0;

            // 快
            for (long long j = (long long) i * i; j < n; j += i) m[j] = 0;
        }
        return result;
    }
};

int main() {

    Solution s;
    cout << s.countPrimes(499979) << endl;

    return 0;
}