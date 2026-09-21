// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        const int n = s.length();
        vector<string> res;
        if (n > 12 || n < 4)
            return res;
        for (int i = 1; i <= 3; i++) {
            if (n - i < 3 || (i > 1 && s[0] == '0') || stoi(s.substr(0, i)) > 255)
                break;
            for (int j = 1; j <= 3; j++) {
                if (n - i - j < 2 || (j > 1 && s[i] == '0') || stoi(s.substr(i, j)) > 255)
                    break;
                for (int k = 1; k <= 3; k++) {
                    if (n - i - j - k < 1 || k > 1 && s[i + j] == '0' || stoi(s.substr(i + j, k)) > 255)
                        break;
                    if (n - i - j - k > 3 ||
                        n - i - j - k > 1 && s[i + j + k] == '0' || stoi(s.substr(i + j + k)) > 255)
                        continue;
                    res.push_back(s.substr(0, i) + '.' + s.substr(i, j) + '.' +
                                  s.substr(i + j, k) + '.' +
                                  s.substr(i + j + k));
                }
            }
        }
        return res;
    }
};