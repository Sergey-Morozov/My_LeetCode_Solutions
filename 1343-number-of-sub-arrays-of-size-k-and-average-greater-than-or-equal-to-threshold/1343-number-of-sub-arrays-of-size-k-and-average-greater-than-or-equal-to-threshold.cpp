// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        long long sum = 0;
        long long goal = threshold * k;
        for (int i = 0; i < k; i++)
            sum += arr[i];
        if (sum >= goal)
            res++;
        for (int i = 0; i < arr.size() - k; i++) {
            sum -= arr[i];
            sum += arr[i + k];
            if (sum >= goal)
                res++;
        }
        return res;
    }
};