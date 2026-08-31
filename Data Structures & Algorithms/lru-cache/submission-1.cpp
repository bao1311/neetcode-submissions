class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
};
class LRUCache {
private:
    Node* left;
    Node* right;
    unordered_map<int, Node*> mp;
    int size;
    void remove(Node* node)
    {
        // This function removes a node and remake the connection between prev and next node of the node we removed
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node* node)
    {
        Node* rightPrev = right->prev;
        rightPrev->next = node;
        node->prev = rightPrev;

        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        this->size = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (!mp.contains(key))
            return -1;
        remove(mp[key]);
        insert(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (!mp.contains(key))
        {
            Node* cur = new Node(key,value);
            mp[key] = cur;
            insert(cur);
        }
        else
        {
            Node* cur = mp[key];
            mp[key]->val = value;
            remove(cur);
            insert(cur);
        }
        if (mp.size() > size)
        {
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
        
    }
};
