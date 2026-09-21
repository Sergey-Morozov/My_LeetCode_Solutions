// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string maskPII(string s) {
        string res{};
        if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
            for (int i = 0; i < s.size(); i++)
                if (s[i] >= 'A' && s[i] <= 'Z')
                    s[i] += 'a' - 'A';
            res = s[0];
            res += "*****";
            int p = s.find('@');
            if (s[p - 1] >= 'A' && s[p - 1] <= 'Z')
                res += s[p - 1] - 'A' + 'a';
            else
                res += s[p - 1];
            res += s.substr(p, s.size() - p);
        } else {
            int count = 0;
            for (char i : s)
                if (i >= '0' && i <= '9')
                    count++;
            switch (count % 10) {
            case 1:
                res = "+*-";
                break;
            case 2:
                res = "+**-";
                break;
            case 3:
                res = "+***-";
                break;
            }
            res += "***-***-";
            for (char i : s)
                if (i >= '0' && i <= '9') {
                    count--;
                    if (count < 4)
                        res += i;
                }
        }
        return res;
    }
};