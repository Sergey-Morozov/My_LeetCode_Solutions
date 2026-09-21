// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int jump(vector<int>& nums) {
        int p1 = 0, p2 = 1, res = 0;
        while (p2 < nums.size()) {
            res++;
            int i = p1;
            p1 = p2;
            while (i < p1) {
                p2 = max(i + nums[i] + 1, p2);
                i++;
            }
        }
        return res;
    }
};