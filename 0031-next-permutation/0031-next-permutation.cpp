// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = nums.size() - 2;
        int val = nums[ind + 1];
        while (ind >= 0) {
            if (nums[ind] >= val) {
                val = nums[ind];
                ind--;
            } else
                break;
        };
        if (ind < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        val = nums[ind];
        int ind2 = ind + 1;
        while ((ind2 < nums.size()) && (nums[ind2] > val)) {
            ind2++;
        };
        ind2--;
        nums[ind] = nums[ind2];
        nums[ind2] = val;
        if (ind < nums.size() - 2)
            sort(nums.begin() + ind + 1, nums.end());
        return;
    }
};