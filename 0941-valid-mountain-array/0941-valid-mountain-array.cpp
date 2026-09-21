// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        int i = 0;
        while (arr[i + 1] > arr[i]) {
            if (i == arr.size() - 2)
                return false;
            i++;
        }
        if (i == 0)
            return false;
        while (arr[i + 1] < arr[i]) {
            if (i == arr.size() - 2)
                return true;
            i++;
        }
        return false;
    }
};