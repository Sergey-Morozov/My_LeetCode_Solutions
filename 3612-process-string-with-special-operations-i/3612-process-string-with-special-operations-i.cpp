// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string processStr(string s) {
        string result, pad;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '*':
                if (result.size() > 0)
                    result.erase(result.size() - 1);
                break;
            case '#':
                pad = result;
                result.append(pad);
                break;
            case '%':
                pad.clear();
                for (int j = result.size() - 1; j >= 0; j--) {
                    pad.append(1, result[j]);
                };
                result = pad;
                break;
            default:
                result.append(1, s[i]);
            }
        }
        return (result);
    }
};