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
        if (index == word.size()) {
            return curr->isWord;
        }
        
        if (word[index] == '.') {
            for (auto &p: curr->letters) {
                if (searchRecursive(word, index + 1, p.second)) {
                    return true;
                }
            }
            return false;
        }

        if (curr->letters.count(word[index]) == 0) {
            return false;
        }
        return searchRecursive(word, index + 1, curr->letters[word[index]]);
    }
};
