// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class MyCircularQueue {
public:
    int size = 0;
    int first = 0;
    int last = 0;
    bool empty = true;
    vector<int> data{};

    MyCircularQueue(int k) {
        size = k;
        for (int i = 0; i < k; i++)
            data.push_back(0);
    }

    bool enQueue(int value) {
        if (last == first && !empty)
            return false;
        data[last] = value;
        last++;
        last %= size;
        empty = false;
        return true;
    }

    bool deQueue() {
        if (last == first && empty)
            return false;
        first++;
        first %= size;
        if (last == first)
            empty = true;
        return true;
    }

    int Front() {
        if (empty)
            return -1;
        else
            return data[first];
    }

    int Rear() {
        if (empty)
            return -1;
        if (last > 0)
            return data[last - 1];
        else
            return data[size - 1];
    }

    bool isEmpty() { return empty; }

    bool isFull() { return (last == first && !empty); }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */