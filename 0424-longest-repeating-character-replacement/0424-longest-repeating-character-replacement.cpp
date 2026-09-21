// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.length();
        if (n <= k + 1)
            return n;
        vector<int> counts(26, 0);
        int lead = 0;
        int i = 0;
        while (i < n && i <= k + lead) {
            lead = max(++counts[s[i] - 'A'], lead);
            ++i;
        }
        if (i == n && i <= k + lead)
            return n;
        --i;
        --counts[s[i] - 'A'];
        int j = 0;
        while (i < n) {
            if (++counts[s[i] - 'A'] <= i - j - k) {
                --counts[s[j] - 'A'];
                ++j;
            }
            ++i;
        }
        return i - j;
    }
};