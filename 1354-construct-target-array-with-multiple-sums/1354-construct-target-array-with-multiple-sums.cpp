// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        sort(target.begin(), target.end());
        int n = target.size() - 1;
        if (n == 0)
            return ((target[0] == 1) ? true : false);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += target[i];
            if (sum >= target[n])
                return false;
        }
      
        while (target[n] != 1) {
            target[n] -= max(((target[n] - target[n - 1]) / sum) * sum, sum);
            if (target[n] < 1)
                return false;
            if (target[n - 1] > target[n]) {
                int i = n - 1;
                while (i >= 0 && target[i] > target[i + 1]) {
                    swap(target[i], target[i + 1]);
                    i--;
                }
                sum -= target[n] - target[i + 1];
            }
        }
        return true;
    }
};