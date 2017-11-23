#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/image-smoother/description/

void display_2d_vector(vector<vector<int>> v)
{
    for(vector<int> vi : v)
    {
        for(int i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

class Solution
{
public:
    // Approach #1: a naive way.
    vector<vector<int>> imageSmoother(vector<vector<int>>& M)
    {
        if(M.size() == 0 || M[0].size() == 0)
            return {{}};
        int row = M.size(), col = M[0].size();

        vector<vector<int>> result(row, vector<int>(col));
        int cnt;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                cnt = 0;
                for(int p = i - 1; p <=  i + 1; ++p)
                {
                    for(int q = j - 1; q <= j + 1; ++q)
                    {
                        if(p < 0 || p >= row || q < 0 || q >= col)
                            continue;
                        result[i][j] += M[p][q];
                        cnt++;
                    }
                }
                result[i][j] /= cnt;
            }
        }
        return result;
    }
};

int main()
{
//    vector<vector<int>> M = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> M = {{100, 100, 1}, {1, 0, 1}};
    display_2d_vector(M);

    Solution s;
    display_2d_vector(s.imageSmoother(M));
    return 0;
}
