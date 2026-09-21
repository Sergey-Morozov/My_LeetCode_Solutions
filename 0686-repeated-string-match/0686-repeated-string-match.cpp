// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int repeatedStringMatch(const string a, const string b) {
        const int n = a.length();
        const int m = b.length();
        for (int i = 0; i < min (n, m); i++) {
            char ch = b[i];
            for (int j = i; j < m; j += n)
                if (b[j] != ch)
                    return -1;
        }
        string tmp = a + a;
        int p = a.find(b);
        if (p >= 0)
            return 1;
        p = tmp.find(b.substr(0, n));
        if (p < 0)
            return -1;
        else if (p == 0 && m % n == 0)
            return (m / n);
        else if (p == 0)
            return ((m / n) + 1);
        else if ((m + p) % n == 0)
            return (((m - n + p) / n) + 1);
        else
            return (((m - n + p) / n) + 2);
    }
};