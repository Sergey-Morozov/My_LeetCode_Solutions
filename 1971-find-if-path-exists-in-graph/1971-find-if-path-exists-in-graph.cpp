// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int clusters[200000];

    int cluster(int i) {
        while (clusters[i] != i)
            i = clusters[i] = clusters[clusters[i]];
        return i;
    }

    void merge(int i, int j) {
        if ((i = cluster(i)) == (j = cluster(j)))
            return;
        clusters[i] = j;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i = 0; i < n; i++)
            clusters[i] = i;
        for (int i = 0; i < edges.size(); i++) 
            merge(edges[i][0], edges[i][1]);
        return cluster(source) == cluster(destination);
    }
};