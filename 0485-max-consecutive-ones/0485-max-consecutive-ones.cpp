// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0;
        for (auto i : nums)
            if (i == 1) {
                count++;
                if (count > res)
                    res++;
            } else
                count = 0;
        return res;
    }
};