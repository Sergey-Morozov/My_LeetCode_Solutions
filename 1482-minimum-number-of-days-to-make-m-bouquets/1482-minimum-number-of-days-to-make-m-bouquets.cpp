// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool tryD(vector<int>& bloomDay, int m, int k, int n, int d) {
        int cnt = 0;
        int beg = 0;
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] > d) {
                cnt += (i - beg) / k;
                if (cnt >= m)
                    return true;
                beg = i + 1;
            }
        }
        cnt += (n - beg) / k;
        if (cnt >= m)
            return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (long(n) < long(m) * long(k))
            return -1;
        int top = 0;
        for (auto i : bloomDay)
            top = max(top, i);
        int beg = 1;
        int end = top;
        while (end > beg) {
            int med = (beg + end) / 2;
            if (tryD(bloomDay, m, k, n, med))
                end = med;
            else
                beg = med + 1;
        }
        return end;
    }
};