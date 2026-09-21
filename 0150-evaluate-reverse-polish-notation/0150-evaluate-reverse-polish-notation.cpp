// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a;
        for (string t : tokens) {
            if (t == "+") {
                a = s.top();
                s.pop();
                s.top() += a;
            } else if (t == "-") {
                a = s.top();
                s.pop();
                s.top() -= a;
            } else if (t == "*") {
                a = s.top();
                s.pop();
                s.top() *= a;
            } else if (t == "/") {
                a = s.top();
                s.pop();
                s.top() /= a;
            } else
                s.push(stoi(t));
        }
        return (s.top());
    }
};