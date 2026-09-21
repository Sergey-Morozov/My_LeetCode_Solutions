// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                int count = 1;
                for (int j = i + 1; j < s.length(); j++) {
                    if (s[j] == '(')
                        count++;
                    else {
                        count--;
                        if (count < 0)
                            break;
                        if ((count == 0) && (j - i + 1 > res))
                            res = j - i + 1;
                    }
                }
            }
        };
        return res;
    }
};