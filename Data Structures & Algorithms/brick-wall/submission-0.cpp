class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int, int> gaps;
        for (vector<int> row: wall) {
            int pos = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                pos += row[i];
                gaps[pos]++;
            }
        }

        int maxVal = 0;
        for (const auto &pair: gaps) {
            maxVal = max(maxVal, pair.second);
        }
        return wall.size() - maxVal;
    }
};