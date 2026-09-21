// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return (int)distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }
};