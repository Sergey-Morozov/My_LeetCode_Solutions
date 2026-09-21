// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int count(vector<int>& nums) {
        int n = nums.size();
        vector<int> gcdl(n);
        vector<int> gcdr(n);
        gcdl[0] = nums[0];
        gcdr[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            gcdl[i] = gcd(gcdl[i - 1], nums[i]);
            gcdr[n - 1 - i] = gcd(gcdr[n - i], nums[n - 1 - i]);
        }
        int count = 0;
        for (int i = 0; i < n - 1; i++)
            if (gcdl[i] == gcdr[i + 1])
                count++;
        return count;
    }

    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();
        if (n == 1)
            return 0;
        int res = count(nums);
        if (n > 2) {
            for (int k = 0; k < n; k++) {
                vector<int> nu{};
                for (int i = 0; i < n; i++)
                    if (i != k)
                        nu.push_back(nums[i]);
                res = max(res, count(nu));
            }
        }
        return res;
    }
};