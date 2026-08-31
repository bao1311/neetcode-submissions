class Node {
    public:
        Node* prev;
        Node* next;
        int key;
        int val;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
        Node(int key, int val, Node* prev, Node* next) {
            this->prev = prev;
            this->next = next;
            this->key = key;
            this->val = val;
        }
};
class LRUCache {
private:
    Node* left;
    Node* right;
    int size;
    unordered_map<int, Node*> mp;
    void remove(Node* node)
    {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node* node)
    {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;

    }
public:
    LRUCache(int capacity) {
        // left and right is fixed
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
        size = capacity; 
    }
    
    int get(int key) {
        if (!mp.contains(key))
            return -1;
        // if contains key, we have to move key to the right
        remove(mp[key]);
        insert(mp[key]);
        return mp[key]->val; 
    }
    
    void put(int key, int value) {
        // if not exist
        if (!mp.contains(key))
        {
            Node* cur = new Node(key,value,right,nullptr);
            mp[key] = cur;
            insert(cur);
        }
        else
        {
            // exists
            Node* cur = mp[key];
            cur->val = value;
            remove(cur);
            insert(cur);
        }
        if (mp.size() > size)
        {
            Node* temp = left->next;
            remove(temp);
            mp.erase(temp->key);
            delete temp;
        }
    }
};
