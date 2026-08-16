class UnionFind {
    unordered_map<int, int> parents;
    unordered_map<int, int> rank;
public:
    int find(int node) {
        if (!parents.count(node)) {
            parents[node] = node;
        }
        int curr = parents[node];
        while (curr != parents[curr]) {
            parents[curr] = parents[parents[curr]];
            curr = parents[curr];
        }
        return curr;
    }

    // true - merged, false - already merged, same parent
    bool unionMethod (int e1, int e2) {
        int par1 = find(e1), par2 = find(e2);
        cout << "par1: " << par1 << ", par2: " << par2 << endl;
        if (par1 == par2) return false;

        if (rank[par1] < rank[par2]) {
            parents[par1] = par2;
            rank[par2]++;
        } else {
            parents[par2] = par1;
            rank[par1]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind *uf = new UnionFind();
        vector<int> resEdge;
        for (const auto &edge: edges) {
            if(!uf->unionMethod(edge[0], edge[1])) {
                resEdge = edge;
            }
        }
        return resEdge;
    }
};
