// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int curr = 0;
        for (int i = 0; i < gain.size(); i++) {
            curr += gain[i];
            res = max(res, curr);
        }
        return res;
    }
};