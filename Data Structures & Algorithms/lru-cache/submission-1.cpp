class Node {
   public:
    int value, key;
    Node *prev, *next;

    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
   private:
    int size;
    Node *head, *tail;
    unordered_map<int, Node*> mp;

    void deleteNodeFromList(Node* node) {
        Node* after = node->next;
        Node* before = node->prev;

        before->next = after;
        after->prev = before;
    }

    void moveNodeToHead(Node* node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

   public:
    LRUCache(int capacity) {
        this->size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
        mp.clear();
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        deleteNodeFromList(node);
        moveNodeToHead(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {  //
            Node* node = mp[key];

            deleteNodeFromList(node);
            moveNodeToHead(node);

            node->value = value;
        } else {
            if (mp.size() == this->size) {
                Node* node = tail->prev;

                deleteNodeFromList(node);
                mp.erase(node->key);

                delete node;
            }

            Node* node = new Node(key, value);
            moveNodeToHead(node);
            mp[key] = node;
        }
    }
};
