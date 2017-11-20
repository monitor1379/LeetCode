#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/plus-one/description/

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int c = 1;
        for(vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
        {
            *it = *it + c;
            if (*it >= 10)
            {
                *it = *it - 10;
                c = 1;
            }
            else
            {
                c = 0;
            }
        }
        if(c)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}
int main()
{
    vector<int> digits = {9};
    display_vector(digits);
    Solution s;
    display_vector(s.plusOne(digits));
    return 0;
}
