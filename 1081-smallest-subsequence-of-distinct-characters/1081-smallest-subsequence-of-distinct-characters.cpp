// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string smallestSubsequence(string s) {
                int n = s.length();
        vector<int> lasts(27);
        lasts[26] = n;
        for (int i = 0; i < n; i++)
            lasts[s[i] - 'a'] = i;
        int beg = 0;
        while (true) {
            char best = s[beg];
            int bestpos = beg;
            int pos = beg + 1;
            while (pos < n && lasts[s[pos - 1] - 'a'] > pos - 1) {
                if (s[pos] < best) {
                    best = s[pos];
                    bestpos = pos;
                }
                pos++;
            }
            for (int i = beg; i < bestpos; i++)
                s[i] = '{';
            beg = bestpos + 1;
            for (int i = beg; i < n; i++)
                if (s[i] == best)
                    s[i] = '{';
            if (pos >= n)
                break;
        }
        string res;
        for (int i = 0; i < n; i++)
            if (s[i] != '{')
                res += s[i];
        return res;
    }
};