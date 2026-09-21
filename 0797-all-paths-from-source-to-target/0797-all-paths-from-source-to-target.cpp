// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
private:
    vector<int> path;

    void walk(vector<vector<int>>& graph, int vertex, int n,
              vector<vector<int>>& res) {
        if (vertex == n - 1) {
            res.push_back(path);
            return;
        }
        for (auto i : graph[vertex]) {
            path.push_back(i);
            walk(graph, i, n, res);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        const int n = graph.size();
        path.reserve(15);
        path.push_back(0);
        walk(graph, 0, n, res);
        return res;
    }
};