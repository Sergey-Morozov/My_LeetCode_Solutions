// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int curr = nums[0];
        int res = 0;
        for (int i = 1; i < n; i++)
            if (nums[i] > curr) {
                res += n - i;
                curr = nums[i];
            }
        return res;
    }
};