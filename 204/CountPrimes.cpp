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
            for (int j = 2; i * j < n; ++j)m[i * j] = 0;
        }
        return result;
    }
};

int main() {

    Solution s;
    cout << s.countPrimes(100) << endl;

    return 0;
}