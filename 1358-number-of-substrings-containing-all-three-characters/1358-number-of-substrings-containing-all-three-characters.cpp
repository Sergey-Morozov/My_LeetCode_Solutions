// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.length();
        int res = 0;
        bool noA = true;
        bool noB = true;
        bool noC = true;
        int i = 0;
        int j = 0;
        int lastA, lastB, lastC;
        while (i < n - 2) {
            while (j < n && (noA || noB || noC)) {
                if (s[j] == 'a') {
                    noA = false;
                    lastA = j;
                } else if (s[j] == 'b') {
                    noB = false;
                    lastB = j;
                } else {
                    noC = false;
                    lastC = j;
                }
                ++j;
            }
            if (noA || noB || noC)
                break;
            int mn = min(lastA, lastB);
            mn = min(mn, lastC);
            res += (mn - i + 1) * (n - j + 1);
            i = mn + 1;
            if (s[mn] == 'a')
                noA = true;
            else if (s[mn] == 'b')
                noB = true;
            else
                noC = true;
        }
        return res;
    }
};