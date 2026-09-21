class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        if (l <= 1)
            return s;
        int besti = 0; // center-left of the pali
        int half = 0;  // symbols left of the center-left of the pali
        bool oddpoly = true;
        int i = 1;
        while(true) {
            int j = 1;
            while (s[i - j] == s[i + j]) {
                j++;
                if ((i < j) || (i + j > l - 1))
                    break;
            };
            if (j > half + 1) {
                besti = i;
                half = j - 1;
                if (i < half)
                    i = half;
            };
            i++;
            if (i >= l - half - 1)
                break;
        };
        i = half;
        while(true) {
            int j = 0;
            while (s[i - j] == s[i + j + 1]) {
                j++;
                if ((i < j) || (i + j > l - 2))
                    break;
            };
            if (j > half) {
                besti = i;
                half = j - 1;
                oddpoly = false;
                if (i < half)
                    i = half;
            };
            i++;
            if (i >= l - half - 1)
                break;
        };
        if (oddpoly)
            return s.substr(besti - half, 2 * half + 1);
        else
            return s.substr(besti - half, 2 * half + 2);
    }
};