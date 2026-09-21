// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string res = "";
        for (int len = 0;; len++) {
            if (strs[0].size() <= len)
                return res;
            char ch = strs[0][len];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].size() <= len)
                    return res;
                if (strs[i][len] != ch)
                    return res;
            };
            res += ch;
        };
        return res;
    };
};