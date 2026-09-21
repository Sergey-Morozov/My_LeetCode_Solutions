// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int res = 0;
        int p1 = 0;
        int p2 = 0;
        for(int i = 0; i < nums.size(); i++){
             int n = nums[i];
             if (n < a) {
                 p1++;
                 p2++;
                 res+= i - p1 + 1;
                 res = res % 1000000007;
             } else if (n <= b) {
                 p2++;
                 res += i - p2 + 1;
                 res = res % 1000000007;
             };
        };
        return res;
    }
};