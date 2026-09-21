// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, bonus = 0;
        for(int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'U') y++;
            else if (moves[i] == 'D') y--;
            else if (moves[i] == 'L') x--;
            else if (moves[i] == 'R') x++;
            else bonus++;
        };
        return (abs(x) + abs(y) + bonus);
    };
};