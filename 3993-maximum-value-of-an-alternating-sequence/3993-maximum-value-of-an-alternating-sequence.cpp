// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
            return s;
        else
            return (s + (static_cast<long long>(m) - 1) * (static_cast<long long>(n) / 2) + 1);
    }
};