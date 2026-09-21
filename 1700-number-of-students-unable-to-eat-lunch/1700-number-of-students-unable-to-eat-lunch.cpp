// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        vector<bool> hungry(n, true);
        int top = 0, res = n;
        bool progress = true;
        while (progress) {
            progress = false;
            for (int i = 0; i < n; i++) {
                if (hungry[i] && sandwiches[top] == students[i]) {
                    progress = true;
                    hungry[i] = false;
                    res--;
                    top++;
                    if (top == n)
                        return 0;
                }
            }
        }
        return res;
    }
};