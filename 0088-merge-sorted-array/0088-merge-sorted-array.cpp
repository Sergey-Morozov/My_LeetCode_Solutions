// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> buff;
        int p1 = 0;
        int p2 = 0;
        if (n == 0)
            return;
        if (m == 0) {
            swap(nums1, nums2);
            return;
        }
        while (p1 + p2 < m + n) {
            if (p2 == n || p1 < m && nums1[p1] < nums2[p2]) {
                buff.push_back(nums1[p1]);
                ++p1;
            } else {
                buff.push_back(nums2[p2]);
                ++p2;
            }
        }
        swap(nums1, buff);
    }
};