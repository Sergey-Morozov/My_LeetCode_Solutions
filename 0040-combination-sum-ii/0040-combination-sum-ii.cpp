// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    unordered_map<int, int> terms{};
    vector<vector<int>> out{};

    void walker(vector<int>& path, unordered_map<int, int>::iterator curr,
                int rest, int count) {
        if (rest == 0) {
            out.push_back(path);
        }
        if ((rest <= 0) || (curr == terms.end()))
            return;
        int val = curr->first;
        if (count < curr->second) {
            path.push_back(curr->first);
            walker(path, curr, rest - curr->first, count + 1);
            path.pop_back();
        }
        walker(path, ++curr, rest, 0);
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (auto i : candidates) {
            auto j = terms.find(i);
            if (j == terms.end())
                terms.emplace(make_pair(i, 1));
            else
                j->second++;
        }
        vector<int> path{};
        walker(path, terms.begin(), target, 0);
        return out;
    }
};