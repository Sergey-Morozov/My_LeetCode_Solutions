// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        int res = 0;
        if (s2.empty())
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        res = s2.top();
        s2.pop();
        return res;
    }

    int peek() {
        if (s2.empty())
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        return s2.top();
    }

    bool empty() { return (s1.empty() && s2.empty()); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */