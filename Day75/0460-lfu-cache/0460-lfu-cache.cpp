class LFUCache {
private:
    struct Node {
        int key, val, freq;
        Node *prev, *next;
        Node(int _key, int _val) : key(_key), val(_val), freq(1), prev(nullptr), next(nullptr) {}
    };
    
    struct DLL {
        Node *head, *tail;
        int size;
        DLL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addNode(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }
        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        Node* removeLast() {
            if (size > 0) {
                Node* node = tail->prev;
                removeNode(node);
                return node;
            }
            return nullptr;
        }
    };
    
    int capacity, currSize, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLL*> freqList;
    
    void updateFreq(Node* node) {
        int freq = node->freq;
        freqList[freq]->removeNode(node);
        if (freq == minFreq && freqList[freq]->size == 0) {
            minFreq++;
        }
        node->freq++;
        if (freqList.find(node->freq) == freqList.end()) {
            freqList[node->freq] = new DLL();
        }
        freqList[node->freq]->addNode(node);
    }
    
public:
    LFUCache(int cap) {
        capacity = cap;
        currSize = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;
        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        } else {
            if (currSize == capacity) {
                Node* node = freqList[minFreq]->removeLast();
                keyNode.erase(node->key);
                currSize--;
            }
            Node* newNode = new Node(key, value);
            minFreq = 1;
            if (freqList.find(minFreq) == freqList.end()) {
                freqList[minFreq] = new DLL();
            }
            freqList[minFreq]->addNode(newNode);
            keyNode[key] = newNode;
            currSize++;
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */