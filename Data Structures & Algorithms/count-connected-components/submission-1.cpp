class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    
    int numOfComponents = 0;

    int find(int node){
        int curr = node;
        while (parent[curr] != curr){
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }

    bool union_(int x, int y){
        int parx = find(x), pary = find(y);

        if (parx == pary) return false;

        if (rank[parx] > rank[pary]){
            parent[pary] = parx;
        } else if (rank[parx] < rank[pary]){
            parent[parx] = pary;
        } else {
            parent[pary] = parx;
            rank[parx]++;
        }
        numOfComponents--;
        return true;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        numOfComponents = n;

        for (vector<int> edge: edges){
            union_(edge[0], edge[1]);
        }
        return numOfComponents;
    }
};
