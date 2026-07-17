struct NodeL {
    int val;
    NodeL* next;
    NodeL* prev;
    NodeL(int v, NodeL* n = nullptr, NodeL* p = nullptr): val(v), next(n), prev(p) {}
};

class MyLinkedList {
    NodeL* head, * tail;
    int size;
public:
    MyLinkedList() {
        head = new NodeL(0, nullptr, nullptr);
        tail = new NodeL(0, nullptr, nullptr);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    NodeL* searchForIndex(int idx) {
        if (idx > size) return nullptr;

        int tmp = 0;
        NodeL* node = head->next;
        while (tmp < idx) {
            node = node->next;
            tmp++;
        }
        return node;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        NodeL* node = searchForIndex(index);
        return node->val;
    }
    
    void addAtHead(int val) {
        size++;
        NodeL* node = new NodeL(val, head->next, head);
        head->next->prev = node;
        head->next = node;
    }
    
    void addAtTail(int val) {
        size++;
        NodeL* node = new NodeL(val, tail, tail->prev);
        tail->prev->next = node;
        tail->prev = node;
    }
    
    void addAtIndex(int index, int val) {
        NodeL* node = searchForIndex(index);
        if (!node) return;
        size++;
        NodeL* newNode = new NodeL(val, node, node->prev);
        node->prev->next = newNode;
        node->prev = newNode;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        NodeL* node = searchForIndex(index);
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */