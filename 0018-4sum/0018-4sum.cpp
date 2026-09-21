// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 4)
            return {};
        vector<vector<int>> res{};
        int i = 0;
        while (i < n - 3) {
            int first = nums[i];
            if ((i > 0) && (first == nums[i - 1])) {
                i++;
                continue;
            };
            int j = i + 1;
            while (j < n - 2) {
                int second = nums[j];
                if ((j > i + 1) && (second == nums[j - 1])) {
                    j++;
                    continue;
                };
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    if (static_cast<long long int>(first) + static_cast<long long int>(second) + static_cast<long long int>(nums[left]) + static_cast<long long int>(nums[right]) < static_cast<long long int>(target))
                        left++;
                    else if (static_cast<long long int>(first) + static_cast<long long int>(second) + static_cast<long long int>(nums[left]) + static_cast<long long int>(nums[right]) > static_cast<long long int>(target))
                        right--;
                    else {
                        res.push_back({first, second, nums[left], nums[right]});
                        left++;
                        while ((nums[left] == nums[left - 1]) && (left < right))
                            left++;
                    };
                };
                j++;
            };
            i++;
        };
        return res;
    }
};