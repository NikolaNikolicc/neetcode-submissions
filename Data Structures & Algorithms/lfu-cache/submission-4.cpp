struct LFUNode {
    int key, val, cnt;
    LFUNode *next, *prev;
    LFUNode(int k = 0, int v = 0) : key(k), val(v), cnt(1), next(nullptr), prev(nullptr) {}
};

class LFUCache {
    int cap;
    int size;
    int minFreq;
    unordered_map<int, LFUNode*> nodes;
    unordered_map<int, pair<LFUNode*, LFUNode*>> freqHeadsTails;

    // pravi nivo (head/tail sentinele) samo ako ne postoji
    void ensureLayer(int level) {
        if (freqHeadsTails.count(level)) return;
        LFUNode *head = new LFUNode(), *tail = new LFUNode();
        head->next = tail;
        tail->prev = head;
        freqHeadsTails[level] = {head, tail};
    }

    // izvadi čvor iz liste u kojoj je
    void unlink(LFUNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = node->next = nullptr;
    }

    // ubaci čvor na kraj nivoa node->cnt (najnoviji)
    void pushBack(LFUNode *node) {
        ensureLayer(node->cnt);
        LFUNode *tail = freqHeadsTails[node->cnt].second;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    // briše nivo ako je prazan, vraća true ako je obrisan
    bool deleteLayerIfEmpty(int level) {
        auto it = freqHeadsTails.find(level);          // find, ne operator[]
        if (it == freqHeadsTails.end()) return false;
        if (it->second.first->next != it->second.second) return false;
        delete it->second.first;
        delete it->second.second;
        freqHeadsTails.erase(it);
        return true;
    }

    // postojeći čvor: cnt -> cnt + 1
    void promote(LFUNode *node) {
        int old = node->cnt;
        unlink(node);
        if (deleteLayerIfEmpty(old) && minFreq == old) minFreq = old + 1;
        node->cnt++;
        pushBack(node);
    }

    // izbaci najstariji čvor sa najniže frekvencije
    void evict() {
        LFUNode *head = freqHeadsTails[minFreq].first;
        LFUNode *victim = head->next;                  // najstariji, ne tail->prev
        unlink(victim);
        nodes.erase(victim->key);
        deleteLayerIfEmpty(minFreq);
        delete victim;
        size--;
    }

public:
    LFUCache(int capacity) : cap(capacity), size(0), minFreq(0) {}

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
        auto it = nodes.find(key);
        if (it == nodes.end()) return -1;
        promote(it->second);
        return it->second->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;
        auto it = nodes.find(key);
        if (it != nodes.end()) {
            it->second->val = value;
            promote(it->second);
            return;
        }
        if (size == cap) evict();
        LFUNode *node = new LFUNode(key, value);       // cnt = 1
        nodes[key] = node;
        pushBack(node);
        minFreq = 1;
        size++;
    }
};