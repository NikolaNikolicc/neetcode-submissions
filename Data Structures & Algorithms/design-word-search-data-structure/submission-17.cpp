struct PrefixTreeNode {
    unordered_map<char, PrefixTreeNode*> letters;
    bool isWord = false;
};

class WordDictionary {
    PrefixTreeNode *head;
public:
    WordDictionary() {
        head = new PrefixTreeNode();
    }
    
    void addWord(string word) {
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
        return searchRecursive(word, 0, head);
    }

    bool searchRecursive(const string &word, int index, PrefixTreeNode *curr) {
        for (int i = index; i < word.size(); i++) {
            char ch = word[i];
            if (ch == '.') {
                for (const auto& p: curr->letters) {
                    if (searchRecursive(word, i + 1, p.second)) return true;
                }
                return false;
            } else if (curr->letters.count(ch)) {
                curr = curr->letters[ch];
            } else {
                return false;
            }
        }
        return curr->isWord;
    }
};
