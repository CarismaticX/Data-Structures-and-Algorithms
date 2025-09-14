class Node {
    public:
    string data;
    Node* back;
    Node* next;
public:
    Node(string val) {
        data = val;
        back = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;   // clear forward history by overwriting
        newNode->back = curr;
        curr = newNode;
    }
    
    string back(int steps) {
        while (steps > 0 && curr->back) {
            curr = curr->back;
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while (steps > 0 && curr->next) {
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};




/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */