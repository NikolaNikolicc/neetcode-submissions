class UnionFind {
    unordered_map<int, int> rank;
    unordered_map<int, int> parent; 
    int cnt;
public:
    void initialize(int n) {
        cnt = n;
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int componentsRemaining() {return cnt;}

    int findParent(int node){
        while (node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool unionNodes(int node1, int node2) {
        int par1 = findParent(node1), par2 = findParent(node2);

        if (par1 == par2) return false;

        if (rank[par1] > rank[par2]) {
            rank[par1] += rank[par2];
            parent[par2] = par1;
        } else {
            rank[par2] += rank[par1];
            parent[par1] = par2;
        }
        cnt--;
        return true;
    }

};

struct Comparator {
    bool operator() (vector<int> &v1, vector<int> &v2) {
        return v1[2] > v2[2];
    }
};

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        UnionFind uf;
        uf.initialize(n);
        int mst = 0;
        priority_queue<vector<int>, vector<vector<int>>, Comparator> minHeap;
        for (auto &edge: edges) {
            minHeap.push(edge);
        }

        while (uf.componentsRemaining() != 1 && !minHeap.empty()) {
            vector<int> edge = minHeap.top(); minHeap.pop();
            int u = edge[0], v = edge[1], w = edge[2];

            if (uf.unionNodes(u, v)) {
                mst += w;
            }
        }

        return (uf.componentsRemaining() == 1) ? mst : -1;
    }
};
