// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        for (int i = 1; i < n; i++) {
            int l = height[i];
            int lead = height[0];
            for (int k = 0; k < i; k++) {
                int h = height[k];
                if (k > 0)
                    if (h <= lead)
                        continue;
                int cand = min(l, h) * (i - k);
                if (cand > res)
                    res = cand;
                if (h >= l)
                    break;
                lead = h;
            };
        };
        return res;
    }
};