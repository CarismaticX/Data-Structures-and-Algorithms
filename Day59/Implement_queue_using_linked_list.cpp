#include <bits/stdc++.h>
using namespace std;

class QueueNode {
public:
    int val;
    QueueNode* next;
    QueueNode(int data) {
        val = data;
        next = nullptr;
    }
};

class Queue {
    QueueNode *Front, *Rear;
    int size;
public:
    Queue() {
        Front = Rear = nullptr;
        size = 0;
    }
    bool Empty() { return Front == nullptr; }

    void Enqueue(int value) {
        QueueNode* temp = new QueueNode(value);
        if (!Rear) Front = Rear = temp;
        else {
            Rear->next = temp;
            Rear = temp;
        }
        size++;
    }

    void Dequeue() {
        if (Empty()) return;
        QueueNode* temp = Front;
        Front = Front->next;
        if (!Front) Rear = nullptr;
        delete temp;
        size--;
    }

    int Peek() {
        return Empty() ? -1 : Front->val;
    }

    int getSize() { return size; }
};

int main() {
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Dequeue();
    cout << "Front element: " << q.Peek() << endl;
    cout << "Size: " << q.getSize() << endl;
}
