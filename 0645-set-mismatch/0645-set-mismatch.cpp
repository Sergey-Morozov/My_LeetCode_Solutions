// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (nums[i + 1] != nums[i])
            i++;
        int j = 0;
        while (j + 1 == nums[j])
            j++;
        if (j + 1 < nums[j])
            return {nums[i], j + 1};
        j = nums.size() - 1;
        while (j + 1 == nums[j])
            j--;
        return {nums[i], j + 1};
    }
};