// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string longestPrefix(string s) {
        const int n = s.length();
        vector<int> prev(n, 0);
        prev[0] = 0;
        int i = 1;
        int j = 0;
        while (i < n) {
            if (s[i] == s[j]) {
                j++;
                prev[i] = j;
                i++;
            } else {
                if (j > 0)
                    j = prev[j - 1];
                else {
                    prev[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0, prev[n - 1]);
    }
};