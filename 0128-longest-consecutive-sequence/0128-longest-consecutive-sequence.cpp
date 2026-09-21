// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> m(nums.begin(), nums.end());
        for (auto i : m) {
            if (m.contains(i - 1))
                continue;
            int next = i + 1;
            for (; m.contains(next) ; next++);
            res = max(res, next - i);
        }
        return res;
    }
};