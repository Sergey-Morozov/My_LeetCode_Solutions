// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    long long sumScores(string s) {
        const int n = s.size();
        long long res = n;
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            int k = 0;
            if (i < r) {
                k = min(r - i, z[i - l]);
            }
            while (i + k < n && s[k] == s[i + k]) {
                k++;
            }
            if (i + k > r) {
                l = i;
                r = i + k;
            }
            res += k;
            z[i] = k;
        }
        return res;
    }
};
