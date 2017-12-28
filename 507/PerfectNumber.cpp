#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/perfect-number/description/

class Solution {
public:
    bool checkPerfectNumber2(int num) {
        if (num == 1) return false;
        int sum = 1;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
            }
        }
        return sum == num;
    }

    /*
     * Approach: Euclid-Euler Theorem
     *
     * Euclid proved that 2^(p−1) * (2^p - 1) is an even perfect number
     * whenever 2^p - 1 is prime, where p is prime.
     *
     * Time complexity:  O(logn)
     * Space complexity: O(logn)
     *
     */
    bool checkPerfectNumber(int num) {
        vector<int> p = {2, 3, 5, 7, 13, 17, 19, 31};
        vector<int> k;
        for (int i: p)
            k.push_back((1 << (i - 1)) * ((1 << i) - 1));
        for (int i: k)
            if (i == num)
                return true;
        return false;
    }
};

int main() {


    Solution s;
    cout << s.checkPerfectNumber(28) << endl;


    return 0;
}