// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> res2{};
            for (auto j : res) {
                for (int k = 0; k < nums.size(); k++) {
                    bool found = false;
                    for (int l = 0; l < i; l++) {
                        if (j[l] == nums[k]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        vector<int> tmp = j;
                        tmp.push_back(nums[k]);
                        res2.push_back(tmp);
                    }
                }
            }
            swap(res, res2);
        }
        return res;
    }
};