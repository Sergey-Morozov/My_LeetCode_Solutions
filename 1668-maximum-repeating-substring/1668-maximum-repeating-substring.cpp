// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int m = word.length();
        int res = 0;
        int curr = 0;
        int i = 0;
        while (i <= n - m) {
            bool ok = true;
            for (int j = i; j < i + m; j++)
                if (sequence[j] != word[j - i]) {
                    ok = false;
                    break;
                }
            if (ok) {
                curr++;
                i += m;
            } else {
                res = max(res, curr);
                i -= curr * m;
                curr = 0;
                i++;
            }
        }
        res = max(res, curr);
        return res;
    }
};