// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<int> curr;
        int t1, t2;
        for (string s : logs) {
            int pos = s.find(":start:");
            if (pos >= 0) {
                t2 = stoi(s.substr(pos + 7, s.length() - pos - 7));
                if (!curr.empty())
                    times[curr.top()] += t2 - t1;
                curr.push(stoi(s.substr(0, pos)));
            } else {
                pos = s.find(":end:");
                t2 = stoi(s.substr(pos + 5, s.length() - pos - 5)) + 1;
                times[curr.top()] += t2 - t1;
                curr.pop();
            }
            t1 = t2;
        }
        return times;
    }
};