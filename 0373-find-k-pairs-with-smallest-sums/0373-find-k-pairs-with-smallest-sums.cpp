// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> res;
        struct post {
            int y;
            int sum;
        };
        vector<post> bdr;
        int n1 = nums1.size();
        int n2 = nums2.size();
        bdr.push_back({0, nums1[0] + nums2[0]});
        int count = 0;
        while (count < k) {
            int min = bdr[0].sum;
            int minx = 0;
            for (int i = 1; i < bdr.size(); i++)
                if (bdr[i].sum < min) {
                    min = bdr[i].sum;
                    minx = i;
                }
            res.push_back({nums1[minx], nums2[bdr[minx].y]});
            count++;
            bdr[minx].y++;
            if (bdr[minx].y == n2)
                bdr[minx].sum = INT_MAX;
            else
                bdr[minx].sum = nums1[minx] + nums2[bdr[minx].y];
            if (minx == bdr.size() - 1 && bdr[minx].y == 1 && minx < n1 - 1)
                bdr.push_back({0, nums1[minx + 1] + nums2[0]});
        }
        return res;
    }
};