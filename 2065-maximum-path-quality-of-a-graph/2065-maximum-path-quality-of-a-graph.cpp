// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
private:
    static const unsigned maxEdgesPerNode = 4;
    static const unsigned maxNodes = 1000;
    typedef uint16_t entry_t;
    entry_t nt[maxNodes][maxEdgesPerNode][2];
    vector<int> path, tmp, dtz;
    vector<bool> firstStep;
    int res = 0;

    void walker(entry_t maxTime_, entry_t time_, vector<int>& values) {
        int here = path.back();
        if (here == 0) {
            tmp = path;
            sort(tmp.begin(), tmp.end());
            int quality = values[tmp[0]];
            for (int i = 1; i < tmp.size(); i++)
                if (tmp[i - 1] != tmp[i])
                    quality += values[tmp[i]];
            if (res < quality)
                res = quality;
        }
        int i = 0;
        while (i < maxEdgesPerNode && nt[here][i][0] != maxNodes) {
            if (time_ + nt[here][i][1] + dtz[nt[here][i][0]] <= maxTime_ &&
                (here != 0 || firstStep[i])) {
                if (here == 0)
                    firstStep[i] = false;
                path.push_back(nt[here][i][0]);
                walker(maxTime_, time_ + nt[here][i][1], values);
                path.pop_back();
                if (here == 0)
                    firstStep[i] = true;
            }
            i++;
        }
    }

public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges,
                           int maxTime) {
        const int n = values.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < maxEdgesPerNode; j++)
                nt[i][j][0] = maxNodes;
        for (int i = 0; i < edges.size(); i++) {
            int j = 0;
            while (nt[edges[i][0]][j][0] != maxNodes)
                j++;
            nt[edges[i][0]][j][0] = edges[i][1];
            nt[edges[i][0]][j][1] = edges[i][2];
            j = 0;
            while (nt[edges[i][1]][j][0] != maxNodes)
                j++;
            nt[edges[i][1]][j][0] = edges[i][0];
            nt[edges[i][1]][j][1] = edges[i][2];
        }
        dtz = vector<int>(n, maxTime);
        dtz[0] = 0;
        path.reserve(n);
        tmp.reserve(n);
        tmp.push_back(0);
        int i = 0;
        int ti = 0;
        do {
            int j = 0;
            while (j < maxEdgesPerNode && nt[ti][j][0] != maxNodes) {
                int ntij = nt[ti][j][0];
                if (dtz[ntij] == maxTime) {
                    dtz[ntij] = dtz[ti] + nt[ti][j][1];
                    tmp.push_back(ntij);
                    int k = tmp.size() - 1;
                    while (dtz[tmp[k - 1]] > dtz[tmp[k]]) {
                        swap(tmp[k - 1], tmp[k]);
                        k--;
                    }
                } else if (dtz[ti] + nt[ti][j][1] < dtz[ntij]) {
                    dtz[ntij] = dtz[ti] + nt[ti][j][1];
                    auto k = find(tmp.begin() + i, tmp.end(), ntij);
                    while (dtz[*(k - 1)] > dtz[*k]) {
                        swap(*(k - 1), *k);
                        k--;
                    }
                }
                j++;
            }
            i++;
        } while (i < tmp.size() && dtz[ti = tmp[i]] <= maxTime / 2);
        firstStep = vector<bool>(maxEdgesPerNode, true);
        path = vector<int>{0};
        walker(maxTime, 0, values);
        return res;
    }
};