class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    int components;

public:
    UnionFind(int n) : parent(n), size(n, 1), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        // Union by size
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        components--;

        return true;
    }

    bool isConnected() const {
        return components == 1;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            edges[i].push_back(i); // store original index
        }
        
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        int baseMST = 0;
        UnionFind uf(n);
        for (vector<int> edge: edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            if (uf.union_(a, b)) {
                baseMST += w;
            }
        }

        vector<int> criticalEdges;
        vector<int> pseudoEdges;

        for (int i = 0; i < m; i++) {
            
            UnionFind criticalUF(n);
            int criticalMST = 0;
            
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                const vector<int>& edge = edges[j];
                if (criticalUF.union_(edge[0], edge[1])) {
                    criticalMST += edge[2];
                }
            }

            if (criticalMST != baseMST || !criticalUF.isConnected()) {
                criticalEdges.push_back(edges[i][3]);
                continue;
            }

                        UnionFind pseudoUF(n);
            int pseudoMST = edges[i][2];
            pseudoUF.union_(edges[i][0], edges[i][1]);
            
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                const vector<int>& edge = edges[j];
                if (pseudoUF.union_(edge[0], edge[1])) {
                    pseudoMST += edge[2];
                }
            }
            
            if (pseudoMST == baseMST && pseudoUF.isConnected()) {
                pseudoEdges.push_back(edges[i][3]);
            }
        }

        return {criticalEdges, pseudoEdges};

    }
};