/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> umap;
public:
    Node* cloneGraph(Node* node) {
        if (!node)return nullptr;

        if (umap.count(node->val) == 0) {
            umap[node->val] = new Node(node->val);

            for(Node* nei: node->neighbors) {
                Node* n = cloneGraph(nei);
                umap[node->val]->neighbors.push_back(n);
            }
        }
        return umap[node->val];
    }
};
