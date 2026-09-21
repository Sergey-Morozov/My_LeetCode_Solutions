// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int sum = 0;
        int oldsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum %= k;
            if (s.contains(sum) && i > 0)
                return true;
            s.insert(oldsum);
            oldsum = sum;
        }
        return false;
    }
};