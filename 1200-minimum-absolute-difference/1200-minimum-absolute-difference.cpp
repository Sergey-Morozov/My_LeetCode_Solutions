// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dist = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++)
            dist = min(dist, arr[i + 1] - arr[i]);
        vector<vector<int>> res;
        for (int i = 0; i < arr.size() - 1; i++)
            if (arr[i + 1] - arr[i] == dist)
                res.push_back({arr[i], arr[i + 1]});
        return res;
    }
};