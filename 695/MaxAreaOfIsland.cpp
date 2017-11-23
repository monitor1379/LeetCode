#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/max-area-of-island/description/

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
    // Depth-first search
    // Time complexity: O(row * col)
    // Space complexity: O(row * col)
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxArea = 0, row = grid.size(), col = grid[0].size();
        vector<vector<int>> mask = create_mask(row, col);
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                maxArea = max(maxArea, search_area(grid, mask, i, j));
        return maxArea;
    }

    int search_area(vector<vector<int>>&grid, vector<vector<int>>&mask, int i, int j)
    {
        int row = grid.size(), col = grid[0].size();
        if(i < 0 || i >= row || j < 0 || j >= col || mask[i][j] == 1 || grid[i][j] == 0)
            return 0;

        mask[i][j] = 1;
        int up = search_area(grid, mask, i - 1, j);
        int down = search_area(grid, mask, i + 1, j);
        int left = search_area(grid, mask, i, j - 1);
        int right = search_area(grid, mask, i, j + 1);
        return 1 + up + down + left + right;

    }

    vector<vector<int>> create_mask(int row, int col)
    {
        vector<vector<int>> mask(row);
        for(int i = 0; i < row; ++i)
            mask[i] = vector<int>(col);
        return mask;
    }
};

int main()
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

//    vector<vector<int>> grid = {{0,0,0,0,0},
//        {0,1,1,1,0},
//        {0,0,1,0,0}
//    };


//    vector<vector<int>> grid = {{0,0,0,0,0}};

    Solution s;
    display_2d_vector(grid);
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}
