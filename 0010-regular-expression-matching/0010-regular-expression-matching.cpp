// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution
{
public:
    bool check(string s, string test)
    {
        if (s.length() < test.length())
        {
            return false;
        };
        for (int i = 0; i < test.length(); i++)
        {
            if ((s[i] != test[i]) && (test[i] != '.'))
            {
                return false;
            }
        };
        return true;
    }

    bool isMatch(string s, string p)
    {
        set<string> candstrings{}, newcandstrings{};
        candstrings.insert("");
        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == '*')
            {
                continue;
            }
            newcandstrings.clear();
            for (string candstring : candstrings)
            {
                if ((i < p.length() - 1) && (p[i + 1] == '*'))
                {
                    while (check(s, candstring))
                    {
                        if (candstring.length() <= s.length())
                        {
                            newcandstrings.insert(candstring);
                            candstring += p[i];
                        };
                    };
                }
                else
                {
                    candstring += p[i];
                    if (check(s, candstring))
                    {
                        if (candstring.length() <= s.length())
                        {
                            newcandstrings.insert(candstring);
                        }
                    }
                };
            };
            swap(candstrings, newcandstrings);
        }
        for (string candstring : candstrings)
        {
            if (s.length() == candstring.length() && check(s, candstring))
            {
                return true;
            }
        };
        return (false);
    };
};
