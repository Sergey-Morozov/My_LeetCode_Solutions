// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans{nums};
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};