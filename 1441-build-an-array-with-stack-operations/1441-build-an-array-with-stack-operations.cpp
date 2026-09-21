// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int curr = 0;
        for (int i : target) {
            res.push_back("Push");
            curr += 1;
            while (curr != i) {
                res.push_back("Pop");
                res.push_back("Push");
                curr++;
            }
        }
        return res;
    }
};