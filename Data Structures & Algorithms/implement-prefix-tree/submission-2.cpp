struct PrefixTreeNode {
    unordered_map<char, PrefixTreeNode*> letters;
    bool isWord = false;
};

class PrefixTree {
    PrefixTreeNode *head;
public:
    PrefixTree() {
        head = new PrefixTreeNode();
    }
    
    void insert(string word) {
        PrefixTreeNode *curr = head;
        for (char c: word) {
            if (!curr->letters.count(c)) {
                curr->letters[c] = new PrefixTreeNode();
            }
            curr = curr->letters[c];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        PrefixTreeNode *curr = head;
        for (char c: word) {
            if (!curr->letters.count(c)) return false;
            curr = curr->letters[c];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTreeNode *curr = head;
        for (char c: prefix) {
            if (!curr->letters.count(c)) return false;
            curr = curr->letters[c];
        }
        return true;
    }
};
