struct LRUNode {
    int key;
    int val;
    LRUNode* prev;
    LRUNode* next;

    LRUNode(int k, int v, LRUNode* p = nullptr, LRUNode* n = nullptr): key(k), val(v), prev(p), next(n) {}
    LRUNode(): key(-1), val(-1), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    int cap = 0, size = 0;
    unordered_map<int, LRUNode*> elems;
    LRUNode* head, * tail;

    void unchainElem(LRUNode* node) {
        LRUNode* prev = node->prev;
        LRUNode* next = node->next;

        if (prev) prev->next = next;
        if (next) next->prev = prev;
    }

    void moveToFront(LRUNode* node) {
        if (node->next == tail) return;
        if (elems.count(node->key) > 0) unchainElem(node);
        
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new LRUNode();
        tail = new LRUNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (elems.count(key) > 0) {
            // get element
            LRUNode* elem = elems[key];
            // move to front
            moveToFront(elem);
            // return value
            return elem->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        LRUNode* elem;
        if (elems.count(key) > 0) {
            elem = elems[key];
            // unchainElem(elem);
            moveToFront(elem);
            elem->val = value;
        } else {
            if (size == cap) {
                LRUNode* node = head->next;
                elems.erase(node->key);
                unchainElem(node);
                size--;
            }
            elem = new LRUNode(key, value, tail->prev, tail);
            elems[key] = elem;
            size++;
            tail->prev->next = elem;
            tail->prev = elem;

        }
        // moveToFront(elem);
    }
};
