class UnionFind {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int numComponents;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        numComponents = n;
    }

    int find(int x) {
        int curr = x;
        while (parent[curr] != curr){
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int parx = find(x), pary = find(y);
        if (parx == pary)return false;
        if (rank[parx] > rank[pary]){
            parent[pary] = parx;
        } else if (rank[parx] < rank[pary]){
            parent[parx] = pary;
        } else {
            parent[parx] = pary;
            rank[pary]++;
        }
        numComponents--;
        return true;
    }

    int getNumComponents() {
        return numComponents;
    }
};
