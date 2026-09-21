// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        bool carry = false;
        while (n >= 0 && digits[n] == 9) {
            carry = true;
            digits[n] = 0;
            n--;
        }
        if (n == -1) {
            digits.push_back(0);
            digits[0] = 1;
        } else {
            digits[n]++;
        }
        return digits;
    }
};