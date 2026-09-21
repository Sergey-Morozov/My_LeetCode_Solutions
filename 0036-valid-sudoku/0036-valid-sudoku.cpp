// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (char i = '0'; i <= '9'; i++) {
            for (unsigned char k = 0; k < 9; k++) {
                bool found = false;
                for (unsigned char l = 0; l < 9; l++)
                    if (board[k][l] == i)
                        if (found)
                            return false;
                        else
                            found = true;
            }
            for (unsigned char k = 0; k < 9; k++) {
                bool found = false;
                for (unsigned char l = 0; l < 9; l++)
                    if (board[l][k] == i)
                        if (found)
                            return false;
                        else
                            found = true;
            }
            for (unsigned char k = 0; k < 3; k++)
                for (unsigned char l = 0; l < 3; l++) {
                    bool found = false;
                    for (unsigned char m = 0; m < 3; m++)
                        for (unsigned char n = 0; n < 3; n++)
                            if (board[3 * k + m][3 * l + n] == i)
                                if (found)
                                    return false;
                                else
                                    found = true;
                }
        }
        return true;
    }
};