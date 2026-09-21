// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            nums[i] %= p;
            sum += nums[i];
            if (sum >= p)
                sum -= p;
        }
        if (sum == 0)
            return 0;
        int curr = 0;
        int res = n;
        m.insert({0, -1});
        for (int i = 0; i < n; i++) {
            curr += nums[i];
            if (curr >= p)
                curr -= p;
            int tmp = curr + p - sum;
            if (tmp >= p)
                tmp -= p;
            if (m.find(tmp) != m.end()) {
                res = min(res, i - m[tmp]);
            }
            m[curr] = i;
        }
        if (res == n)
            return -1;
        return res;
    }
};