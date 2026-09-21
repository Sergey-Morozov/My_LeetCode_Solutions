// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool isValid(string s) {
        bool going = true;
        while ((s.length() > 1) && going) {
            int i = 1;
            going = false;
            while (i < s.length()) {
                char ch = s[i];
                if ((ch == ')') && (s[i - 1] == '(')) {
                    s.erase(i - 1, 2);
                    going = true;
                    break;
                } else if ((ch == ']') && (s[i - 1] == '[')) {
                    s.erase(i - 1, 2);
                    going = true;
                    break;
                } else if ((ch == '}') and (s[i - 1] == '{')) {
                    s.erase(i - 1, 2);
                    going = true;
                    break;
                } else
                    i++;
            }
        };
        if (s == "")
            return true;
        else
            return false;
    }
};