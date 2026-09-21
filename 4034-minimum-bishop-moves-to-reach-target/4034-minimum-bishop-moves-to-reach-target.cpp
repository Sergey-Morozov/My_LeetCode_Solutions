// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if ((source[0] + source[1] - target[0] - target[1]) % 2 != 0) return -1;
        if (source[0] == target[0] && source[1] == target[1]) return 0;
        if (abs(source[0] - target[0]) == abs(source[1] - target[1])) return 1;
        return 2;
    }
};