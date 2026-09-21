// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur, vec;
    vector<int> cands;

    void makeSum(const int n, const int target) {
        const int div = cands[n];
        if (n == 0) {
            if (target % div == 0) {
                vec = cur;
                for (int i = 0; i < target / div; i++)
                    vec.push_back(div);
                res.push_back(vec);
            }
        } else {
            makeSum(n - 1, target);
            if (target >= div) {
                cur.push_back(div);
                makeSum(n, target - div);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cur.reserve(80);
        cands = candidates;
        makeSum(candidates.size() - 1, target);
        return res;
    }
};