// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int out = 0, jump = 1;
        while (out + jump < nums.size()) {
            if (nums[out] != nums[out + jump]) {
                nums[out + 1] = nums[out + jump];
                out++;
            } else {
                jump++;
            }
        };
        return ++out;
    }
};