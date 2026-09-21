// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        while (r - l > 2) {
            int m = (r + l) / 2;
            if (arr[m] - arr[m + 1] > 0)
                r = m;
            else
                l = m + 1;
        }
        if (arr[l] > arr[l + 1])
            return l;
        else if (arr[r] > arr[r - 1])
            return r;
        return (r + l) / 2;
    }
};