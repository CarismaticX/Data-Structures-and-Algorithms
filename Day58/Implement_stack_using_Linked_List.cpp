#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Stack {
    Node* top;
    int sz;

public:
    Stack() {
        top = NULL;
        sz = 0;
    }

    void push(int x) {
        Node* element = new Node(x);
        element->next = top;
        top = element;
        sz++;
    }

    int pop() {
        if (top == NULL) return -1; // underflow
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        sz--;
        return val;
    }

    int peek() {
        if (top == NULL) return -1;
        return top->data;
    }

    int size() {
        return sz;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << "\n";       // 30
    cout << "Popped: " << s.pop() << "\n";     // 30
    cout << "Size: " << s.size() << "\n";      // 2
    cout << "Empty? " << s.isEmpty() << "\n";  // 0 (false)

    return 0;
}
