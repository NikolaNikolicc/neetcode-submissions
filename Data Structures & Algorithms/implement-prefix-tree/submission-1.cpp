class PrefixTree {
    struct PTNode {
        unordered_map<char, PTNode*> umap;
        bool isw = false;
    };
    PTNode* root;
public:
    PrefixTree() {
        root = new PTNode();
    }
    
    void insert(string word) {
        PTNode* curr = root;
        for (char ch: word){
            if (!curr->umap.count(ch)){
                curr->umap[ch] = new PTNode();
            }
            curr = curr->umap[ch];
        }
        curr->isw = true;
    }
    
    bool search(string word) {
        PTNode* curr = root;
        for (char ch: word){
            if (!curr->umap.count(ch)){
                return false;
            }
            curr = curr->umap[ch];
        }
        return curr->isw;
    }
    
    bool startsWith(string prefix) {
        PTNode* curr = root;
        for (char ch: prefix){
            if (!curr->umap.count(ch)){
                return false;
            }
            curr = curr->umap[ch];
        }
        return true;
    }
};
