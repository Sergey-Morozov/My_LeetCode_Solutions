// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        long long int order = 1000000000;
            while (order > (x / 10))
                order /= 10;
            order *= 10;
        long long int coorder = 1;
        long long int y = 0; 
        while (order > coorder) {
            y += (order + coorder) * ((x / coorder) % 10);
            order /= 10;
            coorder *= 10;
        }
        if (order == coorder) y += order * ((x / coorder) % 10);
        if (x != y) return false;
        return true;
    }
};