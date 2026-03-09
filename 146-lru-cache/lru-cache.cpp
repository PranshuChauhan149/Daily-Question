class LRUCache {
public:

    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->val = value;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> mp;

    void deleteNode(Node* delNode) {

        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    void addNode(Node* newNode) {

        Node* tempNext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = tempNext;
        tempNext->prev = newNode;
    }

    LRUCache(int capacity) {

        cap = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {

        if(mp.find(key_) != mp.end()) {

            Node* response = mp[key_];
            int res = response->val;

            mp.erase(key_);

            deleteNode(response);
            addNode(response);

            mp[key_] = head->next;

            return res;
        }

        return -1;
    }

    void put(int key_, int value) {

        if(mp.find(key_) != mp.end()) {

            Node* existingNode = mp[key_];
            mp.erase(key_);

            deleteNode(existingNode);
        }

        if(mp.size() == cap) {

            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key_,value));
        mp[key_] = head->next;
    }
};