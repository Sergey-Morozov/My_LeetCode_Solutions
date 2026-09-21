// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0)
                if (nums[i - 1] == nums[i])
                    continue;
            int first = nums[i];
            int end = nums.size() - 1;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (j > i + 1)
                    if (nums[j - 1] == nums[j])
                        continue;
                int second = nums[j];
                int beg = j + 1;
                while (beg < end) {
                    int mid = (beg + end) / 2;
                    if (first + second + nums[mid] < 0)
                        beg = mid + 1;
                    else
                        end = mid;
                };
                if (first + second + nums[end] == 0)
                    res.push_back(vector<int>{first, second, nums[end]});
                if (end <= j + 1) break;
            };
        };
        return res;
    }
};