#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;  // class member queue

public:
    MyStack() {}

    // Push element onto stack
    void push(int x) {
        int s = q.size();
        q.push(x);
        // Rotate previous elements behind the new one
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top and returns it
    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    // Get the top element
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    // Returns whether the stack is empty
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
