// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n =s.length();
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = i; j < n && ok; j++)
                if (s[j] != goal[j - i])
                    ok = false;
            for (int j = 0; j < i && ok; j++)
                if (s[j] != goal[n - i + j])
                    ok = false;
            if (ok)
                return true;
        }
        return false;
    }
};