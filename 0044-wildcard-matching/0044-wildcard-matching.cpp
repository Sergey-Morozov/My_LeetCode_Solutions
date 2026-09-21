// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        vector<bool> fits(n + 1, false);
        fits[0] = true;
        int firstfit = 0;
        for (char ch : p) {
            while ((firstfit < n) && !fits[firstfit])
                firstfit++;
            if (ch == '*') {
                    for (int k = firstfit + 1; k <= n; k++)
                        fits[k] = true;
                    continue;
            }
            for (int i = n; i > firstfit; i--) {
                if ((fits[i - 1]) && ((ch == '?') || (ch == s[i - 1])))
                    fits[i] = true;
                else
                    fits[i] = false;
            }
            fits[firstfit] = false;
        }
        return fits[n];
    }
};