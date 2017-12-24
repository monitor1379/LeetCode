#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/add-digits/description/

class Solution {
public:
    int addDigits(int num) {
        // return (num != 0 && num % 9 == 0) ? 9 : num % 9;
        return 1 + (num - 1) % 9;
    }
};

int main() {
    Solution s;
    cout << s.addDigits(38) << endl;
    cout << s.addDigits(27) << endl;
    cout << s.addDigits(0) << endl;
    return 0;
}