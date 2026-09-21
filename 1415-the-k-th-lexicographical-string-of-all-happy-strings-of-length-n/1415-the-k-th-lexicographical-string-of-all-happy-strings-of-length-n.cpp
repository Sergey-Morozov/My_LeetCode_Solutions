// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
private:
    char more(char ch) {
        if (ch == 'c')
            return 'b';
        return 'c';
    }
    char less(char ch) {
        if (ch == 'a')
            return 'b';
        return 'a';
    }
public:
    string getHappyString(int n, int k) {
        string res;
        int pow = 1<<(n - 1);
        if (k > 3 * pow)
            return "";
        if (k > 2 * pow) {
            res = "c";
            k -= 2 * pow;
        } else if (k > pow) {
            res = "b";
            k -= pow;
        } else
            res = "a";
        while (pow > 1) {
            pow >>= 1;
            if (k > pow) {
                res += more(res.back());
                k -= pow;
            } else
                res += less(res.back());
        }
        return res;
    }
};