class Solution {
public:
    int reverse(int x) {
        int pos = x >= 0 ? 1 : -1;
        if (x == -2147483648) return 0;
        x *= pos;
        string res = to_string(x);
        res = string(res.rbegin(), res.rend());
        if (res.length() > 10) return 0;
        if (res.length() < 10) return pos * stoi(res);
        if (res[0] > '2') return 0;
        else if (res[0] < '2') return pos * stoi(res);
        if (stoi(res.substr(1, 9)) > 147483648) return 0;
        if (res == "2147483648") return pos ? 0 : -2147483648;
       return pos * stoi(res);
    }
};