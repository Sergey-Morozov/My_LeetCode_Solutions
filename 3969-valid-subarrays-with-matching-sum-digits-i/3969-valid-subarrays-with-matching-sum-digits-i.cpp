// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count = 0, i = 0;
        vector<long> sums(nums.size());
        sums.assign(nums.size(), 0);
        char xs = to_string(x)[0];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i; j++) {
                sums[j] += nums[j + i];
                if (sums[j] % 10 != x)
                    continue;
                if (to_string(sums[j])[0] == xs)
                    count++;
            };
        };
        return (count);
    }
};