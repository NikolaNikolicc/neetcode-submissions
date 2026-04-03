class UnionFind {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int maxRank = 0;
public:

    UnionFind(int n){
        for (int i = 0; i < n; i++){
            rank[i] = 1;
            parent[i] = i;
        }
        maxRank = 1;
    }

    int find(int x){
        int curr = x;
        while (parent[curr] != curr){
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }

    bool union_(int x, int y){
        int parx = find(x), pary = find(y);

        if (parx == pary)return false;

        if (rank[parx] > rank[pary]){
            parent[pary] = parx;
            rank[parx] += rank[pary];
            maxRank = max(maxRank, rank[parx]);
        } else if (rank[pary] > rank[parx]){
            parent[parx] = pary;
            rank[pary] += rank[parx];
            maxRank = max(maxRank, rank[pary]);
        } else {
            parent[pary] = parx;
            rank[parx] += rank[pary];
            maxRank = max(maxRank, rank[parx]);
        }
        
        return true;
    }

    int getMaxRank(){return maxRank;}
};

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        UnionFind* uf = new UnionFind(n);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        for (vector<int> edge: edges){
            int w = edge[2], u = edge[0], v = edge[1];
            minHeap.push({w, u, v});
        }

        int mst = 0;
        while (!minHeap.empty() && uf->getMaxRank() != n){
            auto [w, src, dst] = minHeap.top();
            minHeap.pop();

            if (uf->union_(src, dst)){
                mst += w;
            }

        }
        return (uf->getMaxRank() != n) ? -1 : mst;
    }
};
