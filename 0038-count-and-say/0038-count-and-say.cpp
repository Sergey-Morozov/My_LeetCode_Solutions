// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        string newres;
        for (int i = 1; i < n; i++) {
            newres = "";
            int pos = 0;
            while (pos < res.length()) {
                char curr = res[pos];
                int count = 1;
                while (pos < res.length()) {
                    pos++;
                    if (res[pos] == curr)
                        count++;
                    else
                        break;
                }
                newres += to_string(count) + curr;
            }
            swap(res, newres);
        }
        return res;
    }
};