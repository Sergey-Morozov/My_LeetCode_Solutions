// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> curr;
    vector<vector<int>> res;
    void choice(int n, int k, int beg) {
        if (k == 0) {
            res.push_back(curr);
            return;
        }
        for (int i = beg; i < n - k + 2; i++) {
            curr.push_back(i);
            choice(n, k - 1, i + 1);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        curr.reserve(k);
        res.reserve(184756);
        choice(n, k, 1);
        return res;
    }
};