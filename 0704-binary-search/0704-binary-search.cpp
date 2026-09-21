// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        if (nums[l] == target)
            return l;
        return -1;
    }
};