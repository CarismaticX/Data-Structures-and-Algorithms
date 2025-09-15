#include <bits/stdc++.h>
using namespace std;

class Queue {
    int size;
    int *arr;
    int front, rear, currSize;

public:
    Queue(int n = 1000) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
        currSize = 0;
    }

    void push(int x) {
        if (currSize == size) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
        currSize++;
        cout << "The element pushed is " << x << "\n";
    }

    int pop() {
        if (currSize == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % size;
        currSize--;
        if (currSize == 0) front = rear = -1;
        return val;
    }

    int top() {
        if (currSize == 0) return -1;
        return arr[front];
    }

    int getSize() {
        return currSize;
    }
};

int main() {
    Queue q(10);  // create a queue of size 10

    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    cout << "The peek of the queue before deleting any element " << q.top() << "\n";
    cout << "The size of the queue before deletion " << q.getSize() << "\n";

    cout << "The first element to be deleted " << q.pop() << "\n";

    cout << "The peek of the queue after deleting an element " << q.top() << "\n";
    cout << "The size of the queue after deleting an element " << q.getSize() << "\n";

    return 0;
}
