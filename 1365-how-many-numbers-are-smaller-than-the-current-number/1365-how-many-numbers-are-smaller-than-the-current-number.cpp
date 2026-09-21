// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted{nums};
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> amounts;
        int count = 0, curr = -1;
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i] != curr) {
                curr = sorted[i];
                count = i;
            }
            amounts[sorted[i]] = count;
        }
        vector<int> res;
        for (int i = 0; i < sorted.size(); i++) {
            res.push_back(amounts[nums[i]]);
        }
        return res;

    }
};