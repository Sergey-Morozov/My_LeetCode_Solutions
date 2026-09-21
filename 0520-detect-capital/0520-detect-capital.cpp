// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() <= 1)
            return true;
        if (word[0] <= 'z' && word[0] >= 'a') {
            for (int i = 1; i < word.length(); i++)
                if (word[i] < 'a' || word[i] > 'z')
                    return false;
        } else {
            if (word[1] <= 'z' && word[1] >= 'a') {
                for (int i = 2; i < word.length(); i++)
                    if (word[i] < 'a' || word[i] > 'z')
                        return false;
            } else {
                for (int i = 2; i < word.length(); i++)
                    if (word[i] < 'A' || word[i] > 'Z')
                        return false;
            }
        }
        return true;
    }
};