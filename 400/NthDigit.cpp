#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/nth-digit/description/

template<typename T>
string toString(T num) {
    stringstream ss;
    ss << num;
    return ss.str();
}


class Solution {
public:
    //n:       1,2,3,...9 | 10,11,...,99 | 100, 101,..., 999 |
    //#digits:    9       |       90*2   |       900*3       |...|       (len*cnt: total number of digital of each segment)
    //start:   1            10             100           (start number of each segment)
    //len:     1            2              3             (number of digits of each number)
    //cnt:     9            90             900           (total number of each segment)
    int findNthDigit(int n) {

        int t = 9;
        long long len = 1;
        int start = 1;

        // 1. 找到nth digit所在范围，如1-9,10-99,100-999
        while (n - t * len > 0) {
            n -= t * len;
            t *= 10;
            len++;
            start *= 10;
        }

        // 2. 找到nth digit所在的确切数值
        int num = (n - 1) / len + start;

        // 3. 找到nth digit在该数值中的位置
        int k = (n - 1) % len;

        return toString(num)[k] - '0';
    }
};

int main() {

    Solution s;
    cout << s.findNthDigit(3) << endl;
    cout << s.findNthDigit(2147483647) << endl;

    return 0;
}