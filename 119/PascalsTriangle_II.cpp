#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/pascals-triangle-ii/description/

void display_vector(vector<int> v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for(int i = 0; i <= rowIndex; ++i)
            for(int j = i; j > 0; --j)
                result[j] += result[j - 1];
        return result;
    }
};

int main()
{
    int rowIndex = 10;
    Solution s;
    display_vector(s.getRow(rowIndex));
    return 0;
}
