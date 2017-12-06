#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/maximum-swap/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

template<typename T>
string toString(T num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

int stringToInt(string s) {
    stringstream ss;
    ss << s;
    int r;
    ss >> r;
    return r;
}

class Solution {
public:
    /*
     * Approach: Sorting.
     *
     * s1:  12313
     * s2:  33211
     * comp:<<>=>
     *
     * Find the first position i (from left to right) where s1[i] < s2[i],
     * then find the first position j (from right to left) where s1[j] == s2[i],
     * finally swap s1[i] and s2[j].
     *
     * Time complexity:  O(n)
     * Space complexity: O(n)
     */
    int maximumSwap(int num) {
        string s1 = toString(num);
        string s2 = toString(num);
        sort(s2.begin(), s2.end(), greater<int>());
        int i, j;
        for (i = 0; i < s1.size(); ++i)
            if (s1[i] < s2[i])
                break;
        if (i == s1.size()) return num;
        for (j = s1.size() - 1; j >= 0; --j)
            if (s1[j] == s2[i])
                break;
        swap(s1[i], s1[j]);
        return stringToInt(s1);
    }
};

int main() {
    Solution s;
    cout << 2736 << " --> " << s.maximumSwap(2736) << endl;
    cout << 9973 << " --> " << s.maximumSwap(9973) << endl;
    cout << 12313 << " --> " << s.maximumSwap(12313) << endl; // 32311
    return 0;
}