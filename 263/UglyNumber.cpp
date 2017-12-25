#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/ugly-number/description/

class Solution {
public:
    bool isUgly(int num) {
        if (num >= 1 && num <= 5) return true;
        else if (num <= 0) return false;
        else if (num % 2 == 0) return isUgly(num / 2);
        else if (num % 3 == 0) return isUgly(num / 3);
        else if (num % 5 == 0) return isUgly(num / 5);
        else return false;
    }
};

int main() {

    Solution s;

    cout << s.isUgly(0) << endl;
    cout << s.isUgly(1) << endl;
    cout << s.isUgly(2) << endl;
    cout << s.isUgly(5) << endl;
    cout << s.isUgly(6) << endl;
    cout << s.isUgly(8) << endl;
    cout << s.isUgly(14) << endl;

    return 0;
}