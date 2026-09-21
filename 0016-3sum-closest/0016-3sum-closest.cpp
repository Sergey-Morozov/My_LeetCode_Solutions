// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dist = INT_MAX;
        int res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if ((i > 0) && (nums[i - 1] == nums[i]))
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            int goal = target - nums[i];
            while (left < right) {
                int test = nums[left] + nums[right] - goal;
                if (test == 0)
                    return target;
                if (abs(test) < dist) {
                    dist = abs(test);
                    res = test + goal + nums[i];
                };
                if (test < 0)
                    do
                        left++;
                    while ((nums[left] == nums[left - 1]) && (left != right));
                else
                    do
                        right--;
                    while ((nums[right] == nums[right + 1]) && (left != right));
            };
        };
        return res;
    }
};