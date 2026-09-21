// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int row = grid.size();
        const int col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    if (i == 0 || !grid[i - 1][j])
                        res++;
                    if (i == row - 1 || !grid[i + 1][j])
                        res++;
                    if (j == 0 || !grid[i][j - 1])
                        res++;
                    if (j == col - 1 || !grid[i][j + 1])
                        res++;
                }
            }
        return res;
    }
};