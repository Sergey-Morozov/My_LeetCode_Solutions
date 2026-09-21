// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if (n == 1)
            return false;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0)
                continue;
            bool ok = true;
            for (int j = 0; j < i && ok; j++) {
                for (int k = 1; k < n / i && ok; k++)
                    if (s[j] != s[j + k * i])
                        ok = false;
            }
            if (ok)
                return true;
        }
        return false;
    }
};