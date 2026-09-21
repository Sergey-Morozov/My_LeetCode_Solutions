// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int buff;
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++) {
                buff = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = buff;
            }

        if (n % 2 != 0) {
            for (int i = 0; i < n / 2; i++) {
                buff = matrix[i][n / 2];
                matrix[i][n / 2] = matrix[n / 2][i];
                matrix[n / 2][i] = matrix[n - 1 - i][n / 2];
                matrix[n - 1 - i][n / 2] = matrix[n / 2][n - 1 - i];
                matrix[n / 2][n - 1 - i] = buff;
            }
        }
    }
};