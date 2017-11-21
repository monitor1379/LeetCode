#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/pascals-triangle/description/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> t;
        for(int row = 0; row < numRows; ++row)
        {
            t.push_back({});
            if(row == 0)
                t[row].push_back({1});
            else
            {
                for(int col = 0; col <= row; ++col)
                {
                    if(col == 0 || col == row)
                        t[row].push_back(1);
                    else
                        t[row].push_back(t[row - 1][col - 1] + t[row - 1][col]);

                }
            }
        }
        return t;
    }
};

void display_2d_vector(vector<vector<int>> v)
{
    for(size_t i = 0; i < v.size(); ++i)
    {
        for(size_t j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << ", ";
        cout << endl;
    }


    cout << endl;
}

int main()
{
    int numRows = 10;
    Solution s;
    display_2d_vector(s.generate(numRows));
    return 0;
}
