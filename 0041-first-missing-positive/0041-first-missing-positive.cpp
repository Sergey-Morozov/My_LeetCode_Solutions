// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = nums[i];
            while ((j >= 1) && (j <= n)) {
                int k = nums[j - 1];
                nums[j - 1] = j;
                if (k == j)
                    break;
                j = k;
            };
        }
        int res = 1;
        while ((res < n + 1) && (nums[res - 1] == res))
            res++;
        return res;
    }
};