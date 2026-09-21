// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    void switcher(vector<int>& nums, vector<vector<int>>& res, int curr) {
        if (curr == nums.size() - 1) {
            for (auto i : res)
                if (i == nums)
                    return;
            res.push_back(nums);
            return;
        }
        switcher(nums, res, curr + 1);
        for (int i = curr + 1; i < nums.size(); i++) {
            if (nums[curr] != nums[i]) {
                swap(nums[curr], nums[i]);
                switcher(nums, res, curr + 1);
                swap(nums[curr], nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res{};
        switcher(nums, res, 0);
        return res;
    }
};