// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string decodeString(string s) {
        string tmp, res;
        tmp.reserve(10000);
        res.reserve(10000);
        res = s;
        int p = 0;
        stack<int> beg;
        while (p < res.length()) {
            if (res[p] == '[')
                beg.push(p);
            else if (res[p] == ']') {
                int b = beg.top();
                int q = b - 1;
                while (q >= 0 && res[q] >= '0' && res[q] <= '9')
                    q--;
                tmp = res.substr(0, q + 1);
                int i = stoi(res.substr(q + 1, b - q - 1));
                while (i > 0) {
                    tmp += res.substr(b + 1, p - b - 1);
                    i--;
                }
                beg.pop();
                int newp = tmp.length() - 1;
                tmp += res.substr(p + 1);
                swap(tmp, res);
                p = newp;
            }
            p++;
        }
        return res;
    }
};