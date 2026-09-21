// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if ((lower_bound(nums.begin(), nums.end(), target) == nums.end()) || ((int)distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target)) > (int)distance(nums.begin(), --upper_bound(nums.begin(), nums.end(), target)))) {
            vector<int> res{-1, -1};
            return res;
        };
        vector<int> res {(int)distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target)), (int)distance(nums.begin(), --upper_bound(nums.begin(), nums.end(), target))};
        return res;
    }
};