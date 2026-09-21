// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> tails (n, false);
        for (int i = 0; i < edges.size(); i++)
            tails[edges[i][1]] = true;
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (!tails[i])
                res.push_back(i);
        return res;
    }
};