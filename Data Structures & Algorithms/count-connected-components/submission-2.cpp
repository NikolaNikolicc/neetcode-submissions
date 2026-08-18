class UnionFind {
    int numComponents;
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
public:

    UnionFind(int n) {
        numComponents = n;
    }

    int find (int node) {
        if (!parent.count(node)) {
            parent[node] = node;
            rank[node] = 1;
        }
        while (node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    void unionEdges(int from, int to) {
        int par1 = find(from), par2 = find(to);
        if (par1 == par2) return;
        if (rank[par1] < rank[par2]) {
            parent[par1] = par2;
            rank[par2]++;
        } else {
            parent[par2] = par1;
            rank[par1]++;
        }
        numComponents--;
    }

    int getNumComponents() {return numComponents;}
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (vector<int> edge: edges) {
            uf.unionEdges(edge[0], edge[1]);
        }
        return uf.getNumComponents();
    }
};
