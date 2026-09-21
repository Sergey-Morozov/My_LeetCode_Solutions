// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> line(10001, 0);
        int beg = 10000;
        int end = 0;
        vector<bool> points(10001, false);
        vector<bool> atoms(10001, false);
        for (auto i : intervals) {
            line[i[0]]++;
            line[i[1]]--;
            beg = min(beg, i[0]);
            end = max(end, i[1]);
            if (i[0] == i[1])
                atoms[i[0]] = true;
        }
        int sum = 0;
        for (int i = beg; i <= end; i++) {
            sum += line[i];
            if (sum > 0)
                points[i] = true;
        }
        int i = beg;
        vector<vector<int>> res;
        do {
            if (points[i]) {
                int a = i;
                while (i < end && points[i])
                    i++;
                res.push_back({a, i});
                i++;
            }
            while (i <= end && !points[i]) {
                if (atoms[i])
                    res.push_back({i, i});
                i++;
            }
        } while (i < end);
        return res;
    }
};