// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int clusters[100001][2];

    int cluster(int i) {
        while (clusters[i][0] != i)
            i = clusters[i][0] = clusters[clusters[i][0]][0];
        return i;
    }

    void merge(int i, int j, int distance) {
        if ((i = cluster(i)) == (j = cluster(j))) {
            if (distance < clusters[i][1])
                clusters[i][1] = distance;
            return;
        }
        clusters[i][0] = j;
        if (clusters[i][1] < clusters[j][1])
            clusters[j][1] = clusters[i][1];
        if (distance < clusters[j][1])
            clusters[j][1] = distance;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        for (int i = 1; i <= n; i++) {
            clusters[i][0] = i;
            clusters[i][1] = 10001;
        }
        for (int i = 0; i < roads.size(); i++) 
            merge(roads[i][0], roads[i][1], roads[i][2]);
        return clusters[cluster(1)][1];
    }
};
