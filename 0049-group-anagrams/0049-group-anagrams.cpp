// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> keys;
//        keys.reserve(100000);
        for (string i : strs) {
            string s1 = i;
            sort(s1.begin(), s1.end());
            bool found = false;
            for (int j = 0; j < keys.size(); j++) {
                if (s1 == keys[j]) {
                    found = true;
                    res[j].push_back(i);
                    break;
                }
            }
            if (!found) {
                keys.push_back(s1);
                res.push_back({i});
            }
        }
        return res;
    }
};