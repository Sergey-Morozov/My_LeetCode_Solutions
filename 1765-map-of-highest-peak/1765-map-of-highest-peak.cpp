// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
private:
    short q[1000000][2];

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size();
        const int n = isWater[0].size();
        int p1 = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    q[p1][0] = i;
                    q[p1][1] = j;
                    p1++;
                }
                isWater[i][j]--;
            }
        bool finished = false;
        int h = 1;
        int p0 = 0;
        while (p1 < m * n) {
            int p2 = p1;
            for (int p = p0; p < p1; p++) {
                int i = q[p][0];
                int j = q[p][1];
                if (i > 0 && isWater[i - 1][j] == -1) {
                    isWater[i - 1][j] = h;
                    q[p2][0] = i - 1;
                    q[p2][1] = j;
                    p2++;
                }
                if (i < m - 1 && isWater[i + 1][j] == -1) {
                    isWater[i + 1][j] = h;
                    q[p2][0] = i + 1;
                    q[p2][1] = j;
                    p2++;
                }
                if (j > 0 && isWater[i][j - 1] == -1) {
                    isWater[i][j - 1] = h;
                    q[p2][0] = i;
                    q[p2][1] = j - 1;
                    p2++;
                }
                if (j < n - 1 && isWater[i][j + 1] == -1) {
                    isWater[i][j + 1] = h;
                    q[p2][0] = i;
                    q[p2][1] = j + 1;
                    p2++;
                }
            }
            h++;
            p0 = p1;
            p1 = p2;
        }
        return isWater;
    }
};