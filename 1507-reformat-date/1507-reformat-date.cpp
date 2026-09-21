// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    string reformatDate(string date) {
        string res = date.substr(date.length() - 4, 4) + '-';
        if (date.substr(date.length() - 8, 3) == "Jan")
            res += "01-";
        else if (date.substr(date.length() - 8, 3) == "Feb")
            res += "02-";
        else if (date.substr(date.length() - 8, 3) == "Mar")
            res += "03-";
        else if (date.substr(date.length() - 8, 3) == "Apr")
            res += "04-";
        else if (date.substr(date.length() - 8, 3) == "May")
            res += "05-";
        else if (date.substr(date.length() - 8, 3) == "Jun")
            res += "06-";
        else if (date.substr(date.length() - 8, 3) == "Jul")
            res += "07-";
        else if (date.substr(date.length() - 8, 3) == "Aug")
            res += "08-";
        else if (date.substr(date.length() - 8, 3) == "Sep")
            res += "09-";
        else if (date.substr(date.length() - 8, 3) == "Oct")
            res += "10-";
        else if (date.substr(date.length() - 8, 3) == "Nov")
            res += "11-";
        else if (date.substr(date.length() - 8, 3) == "Dec")
            res += "12-";
        if (date[1] < '0' || date[1] > '9') {
            res += '0';
            res += date[0];
        } else {
            res += date[0];
            res += date[1];
        }
        return res;
    }
};