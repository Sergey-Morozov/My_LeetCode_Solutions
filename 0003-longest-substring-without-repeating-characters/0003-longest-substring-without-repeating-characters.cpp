// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        vector<bool> starts(l, true);
        bool found;
        for (int res = 1; res < l; res++) {
            found = false;
            for (int i = 0; i < l - res; i++) {
                if (starts[i]) {
                    if (s[i + res] != s[i]) {
                        found = true;
                    } else {
                        starts[i] = false;
                        if (i > 0)
                            starts[i - 1] = false;
                    }
                } else {
                    if (i > 0)
                        starts[i - 1] = false;
                }
            };
            if (!found)
                return res;
        };
        return l;
    };
};