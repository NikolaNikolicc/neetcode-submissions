class Solution {
private:
    vector<vector<int>> combinations;
    vector<int> combination;
    
    void helper(int pos, int cnt, int n, int k){
        if (cnt == k){
            combinations.push_back(combination);
            return;
        }
        if (pos == n + 1)return;

        combination.push_back(pos);
        helper(pos + 1, cnt + 1, n, k);
        combination.pop_back();

        helper(pos + 1, cnt, n, k);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        helper(1, 0, n, k);
        return combinations;
    }
};