// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int q = n / k;
        for (int i = 0; i < q; i++)
            sort(nums.end() - i * k - k, nums.end() - i * k);
        sort(nums.begin(), nums.end() - q * k);
        vector<int> buff(k);
        for (int i = 1; i <= q; i++) {
            int j = n - 1;
            int l = n - 1 - i * k;
            for (int m = k - 1; m >= 0; m--) {
                if (l < 0 || nums[j] >= nums[l]) {
                    buff[m] = nums[j];
                    j--;
                } else {
                    buff[m] = nums[l];
                    l--;
                }
            }
            for (int m = 0; m < k; m++)
                nums[n - k + m] = buff[m];
        }
        return nums[n - k];
    }
};