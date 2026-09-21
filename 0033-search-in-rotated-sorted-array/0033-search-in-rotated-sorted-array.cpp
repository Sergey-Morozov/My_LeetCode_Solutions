// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[0] == target)
            return 0;
        while (right > left) {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[right] > nums[left] && nums[mid] > target ||
                     nums[right] < nums[left] && nums[mid] > nums[left] &&
                         nums[left] <= target && target <= nums[mid] ||
                     nums[right] < nums[left] && nums[mid] < nums[left] &&
                         (nums[right] < target || target < nums[mid]))
                right = mid;
            else {
                left = mid + 1;
            }
            if (nums[left] == target)
                return left;
        }
        return -1;
    }
};