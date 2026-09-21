// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> keys{{"a", "b", "c"}, {"d", "e", "f"},
                                    {"g", "h", "i"}, {"j", "k", "l"},
                                    {"m", "n", "o"}, {"p", "q", "r", "s"},
                                    {"t", "u", "v"}, {"w", "x", "y", "z"}};
        vector<string> res{};
        if (digits.length() == 1) {
            return keys[digits[0] - '2'];
        } else if (digits.length() == 2) {
            for (int i = 0; i < keys[digits[0] - '2'].size(); i++)
                for (int j = 0; j < keys[digits[1] - '2'].size(); j++)
                    res.push_back(keys[digits[0] - '2'][i] +
                                  keys[digits[1] - '2'][j]);
        } else if (digits.length() == 3) {
            for (int i = 0; i < keys[digits[0] - '2'].size(); i++)
                for (int j = 0; j < keys[digits[1] - '2'].size(); j++)
                    for (int k = 0; k < keys[digits[2] - '2'].size(); k++)
                        res.push_back(keys[digits[0] - '2'][i] +
                                      keys[digits[1] - '2'][j] +
                                      keys[digits[2] - '2'][k]);
        } else {
            for (int i = 0; i < keys[digits[0] - '2'].size(); i++)
                for (int j = 0; j < keys[digits[1] - '2'].size(); j++)
                    for (int k = 0; k < keys[digits[2] - '2'].size(); k++)
                        for (int l = 0; l < keys[digits[3] - '2'].size(); l++)
                            res.push_back(keys[digits[0] - '2'][i] +
                                          keys[digits[1] - '2'][j] +
                                          keys[digits[2] - '2'][k] +
                                          keys[digits[3] - '2'][l]);
        };
        return res;
    }
};