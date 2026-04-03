class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    int maxSize = 0;

    int find(int node){
        
        while (parent[node] != node){
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool union_(int x, int y){
        int parx = find(x), pary = find(y);
        if (parx == pary)return false;

        if (rank[parx] > rank[pary]){
            parent[pary] = parx;
            rank[parx] += rank[pary];
            maxSize = max(maxSize, rank[parx]);
        } else {
            parent[parx] = pary;
            rank[pary] += rank[parx];
            maxSize = max(maxSize, rank[pary]);
        }
        return true;
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        // init
        for (int num: nums){
            if (parent.count(num)) continue;
            parent[num] = num;
            rank[num] = 1;
            maxSize = max(maxSize, rank[num]);
            if (parent.count(num - 1)) union_(num - 1, num);
            if (parent.count(num + 1)) union_(num + 1, num);
        }
        return maxSize;
    }
};
