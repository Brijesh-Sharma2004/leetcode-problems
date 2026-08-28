class LRUCache {
private:
     struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;

    Node* head;
    Node* tail;

    unordered_map<int, Node*> mp;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node) {
        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;

         head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        addNode(node);

        return node->value;
    }
    
    void put(int key, int value) {
         if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            addNode(node);

            return;
    }
    
    Node* newNode = new Node(key, value);

        mp[key] = newNode;
        addNode(newNode);

        if (mp.size() > cap) {

            Node* lru = head->next;

            removeNode(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */