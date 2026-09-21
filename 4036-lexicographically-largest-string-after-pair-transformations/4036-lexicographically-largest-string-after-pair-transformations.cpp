// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int m = nums[i];
            string r ="";
                while (m >= 1 << 25) {
                    m -= 1 << 25;
                    r += 'z';
                }
            int n = 1 << 25;
            char ch = 'z';
            while (m > 0) {
                while (m >= n) {
                    m -= n;
                    r += ch;
                }
                ch--;
                n >>= 1;
            }
            res.push_back(r);
        }
        return res;
    }
};