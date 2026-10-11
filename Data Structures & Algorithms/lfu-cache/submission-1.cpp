
struct LFUNode {
    int key;
    int val;

    LFUNode *next;
    LFUNode *prev;
    int cnt;

    LFUNode(int k = 0, int v = 0): key(k), val(v), next(nullptr), prev(nullptr), cnt(0) { }
};

class LFUCache {
    int cap;
    int size;
    int minFreq;
    unordered_map<int, LFUNode *> nodes;
    unordered_map<int, pair<LFUNode *, LFUNode *>> freqHeadsTails;

    
    void deleteLayer(int level) {
        auto it = freqHeadsTails.find(level);
        // if (it == freqHeadsTails.end()) return;

        if (it->second.first->next != it->second.second) return;
        
        LFUNode *head = freqHeadsTails[level].first;
        LFUNode *tail = freqHeadsTails[level].second;
        
        freqHeadsTails.erase(level);
        delete head;
        delete tail;
        if (minFreq == level) minFreq = INT_MAX;
    }

    void percolateNodeUp (LFUNode *node) {
        // get, 
            // we incremented node cnt, 
            // we unchaining from current level
            // we are going to the next level, to the tail
        // put, 
            // already in structure, 
            // we incremented node cnt
            // we unchaining from current level
            // we are going to the next level, to the tail
        // put,
            // not in a structure,
            // we incremented node cnt
            // we are going to the 1st level, to the tail
        
        LFUNode *next = node->next, *prev = node->prev;
        if (next && prev) {
            next->prev = prev;
            prev->next = next;
            this->deleteLayer(node->cnt - 1);
        }
        if (freqHeadsTails.count(node->cnt) == 0) {
            LFUNode *head = new LFUNode();
            LFUNode *tail = new LFUNode();
            head->next = tail;
            tail->prev = head;
            freqHeadsTails[node->cnt] = {head, tail};
        }
        LFUNode *tail = freqHeadsTails[node->cnt].second;
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
        minFreq = min(minFreq, node->cnt);
    }

    void putToTheFront(LFUNode *node) {
        if (!node) return;
        // increment
        node->cnt++;
        // percolate node up
        this->percolateNodeUp(node);
    }
    
    void relaxCapacity () {
        // TODO, don't forget to erase from map and decrement size
        size--;
        LFUNode* head = freqHeadsTails[minFreq].first;
        LFUNode *nodeForDeletition = head->next;
        
        head->next->next->prev = head;
        head->next = head->next->next;

        nodes.erase(nodeForDeletition->key);
        delete nodeForDeletition;
        this->deleteLayer(minFreq);
    }
    
public:
    LFUCache(int capacity) {
        this->cap = capacity;
        size = 0;
        minFreq = INT_MAX;
    }

    ~LFUCache() {
        for (auto &p : freqHeadsTails) {
            LFUNode *cur = p.second.first;
            while (cur) {
                LFUNode *nxt = cur->next;
                delete cur;
                cur = nxt;
            }
        }
    }

    int get(int key) {
        if (nodes.count(key) == 0) return -1;
        // put to the front
        this->putToTheFront(nodes[key]);
        return nodes[key]->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        if (nodes.count(key)) {
            nodes[key]->val = value;
        } else {
            if (size == cap) {
                this->relaxCapacity();
            }
            nodes[key] = new LFUNode(key, value);
            size++;
        }
        this->putToTheFront(nodes[key]);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */