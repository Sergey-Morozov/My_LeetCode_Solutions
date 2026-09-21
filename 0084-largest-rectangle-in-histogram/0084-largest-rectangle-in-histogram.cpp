// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        struct ltc {
            int left;
            int top;
        };
        vector<ltc> ltcs;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int lastleft = i;
            while (!ltcs.empty() && ltcs.back().top > h) {
                lastleft = ltcs.back().left;
                ltcs.pop_back();
            }
            if (ltcs.empty() || ltcs.back().top < h)
                ltcs.push_back({lastleft, h});
            for (ltc lt : ltcs)
                res = max((i - lt.left + 1) * lt.top, res);
        }
        return res;
    }
};