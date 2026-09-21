// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return nums;
        for (int j = (n - 1) / 2; j >= 0; j--) {
            int i = j;
            while (i < n) {
                int k;
                if (2 * i + 2 < n)
                    k = nums[2 * i + 1] > nums[2 * i + 2] ? 2 * i + 1
                                                          : 2 * i + 2;
                else
                    k = 2 * i + 1;
                if (k < n && nums[i] < nums[k]) {
                    swap(nums[i], nums[k]);
                    i = k;
                } else
                    i = n;
            }
        }
        for (int j = n - 1; j > 0; j--) {
            swap(nums[0], nums[j]);
            int i = 0;
            while (i <= j / 2) {
                int k;
                if (2 * i + 2 < j)
                    k = nums[2 * i + 1] > nums[2 * i + 2] ? 2 * i + 1
                                                          : 2 * i + 2;
                else
                    k = 2 * i + 1;
                if (k < j && nums[i] < nums[k]) {
                    swap(nums[i], nums[k]);
                    i = k;
                } else
                    i = n;
            }
        }
        return nums;
    }
};