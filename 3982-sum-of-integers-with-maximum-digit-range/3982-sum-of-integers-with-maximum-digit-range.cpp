// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int order = 100;
            int range;
            int curr = nums[i];
            int temp = curr;
            int mi = temp % 10;
            int ma = mi;
            while (temp >= 10) {
                temp /= 10;
                mi = min(mi, temp % 10);
                ma = max(ma, temp % 10);
            }
            range = ma - mi;
            if (range == maxRange) sum += curr; else if (range > maxRange) {
                sum = curr;
                maxRange = range;
            };
        };
        return sum;
    }
};