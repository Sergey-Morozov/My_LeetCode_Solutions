// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (int i = 0; i < intervals.size(); ++i)
            m.insert({intervals[i][0], i});
        vector<int> res;
        for (int i = 0; i < intervals.size(); ++i) {
            auto it = m.lower_bound(intervals[i][1]);
            if (it == m.end())
                res.push_back(-1);
            else
                res.push_back(it->second);
        }
        return res;
    }
};