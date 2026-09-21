// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string shortestPalindrome(string s) {
        const int n = s.length();
        if (n <= 1)
            return s;
        string res;
        vector<int> radii(n, 0);
        int c = 0;
        int r = 0;
        int l = 0;
        while (c <= n - 1) {
            while (c - r >= 1 && ((c + r) % 2 == 0 || s[(c - r - 1)/2] == s[(c + r + 1)/2]))
                ++r;
            if (r == c)
                l = c;
            radii[c] = r;
            int oc  = c;
            int oldr = r;
            ++c;
            r = 0;
            while(c < oc + oldr && c <= n - 1) {
                int mc = 2 * oc - c;
                int mmr = oc + oldr - c;
                if (radii[mc] < mmr) {
                    radii[c] = radii[mc];
                    ++c;
                } else if (radii[mc] > mmr) {
                    radii[c] = mmr;
                    ++c;
                } else {
                    r = mmr;
                    break;
                }
            }
        }
        for (int i = n - 1; i > l; --i)
            res += s[i];
        return res + s;
    }
};