// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
private:
    int clusters[50][3];

    int cluster(int i) {
        while (clusters[i][0] != i)
            i = clusters[i][0] = clusters[clusters[i][0]][0];
        return i;
    }

    void merge(int i, int j) {
        if ((i = cluster(i)) == (j = cluster(j))) {
            clusters[i][2]++;
            return;
        }
        if (clusters[i][1] > clusters[j][1])
            swap(i, j);
        clusters[i][0] = j;
        clusters[j][1] += clusters[i][1];
        clusters[j][2] += clusters[i][2] + 1;
        clusters[i][1] = 0;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++) {
            clusters[i][0] = i;
            clusters[i][1] = 1;
            clusters[i][2] = 0;
        }
        for (int i = 0; i < edges.size(); i++)
            merge(edges[i][0], edges[i][1]);
        int res = 0;
        for (int i = 0; i < n; i++)
            if (clusters[i][1] > 0 && clusters[i][2] ==
                    clusters[i][1] * (clusters[i][1] - 1) / 2)
                res++;
        return res;
    }
};