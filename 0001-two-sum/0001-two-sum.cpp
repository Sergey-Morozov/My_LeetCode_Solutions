// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        int beg = 0;
        int fin = nums.size() - 1;
        while (true) {
            if (nums1[beg] + nums1[fin] == target) {
                int i1 = 0;
                while (nums[i1] != nums1[beg])
                    i1++;
                int i2 = nums.size() - 1;
                while (nums[i2] != nums1[fin])
                    i2--;
                vector<int> res{i1, i2};
                return res;
            }
            int mid = (beg + fin) / 2;
            if (nums1[beg] + nums1[fin] < target)
                while (mid > beg)
                    if (nums1[mid] + nums1[fin] < target)
                        beg = mid + 1;
                    else {
                        mid = (beg + mid) / 2;
                        if (mid == beg)
                            beg++;
                    }
            else
                while (mid < fin)
                    if (nums1[mid] + nums1[beg] > target)
                        fin = mid - 1;
                    else {
                        mid = (fin + mid) / 2;
                        if (mid == fin - 1)
                            fin--;
                    }
        }
    }
};