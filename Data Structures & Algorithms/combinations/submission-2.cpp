class Solution {
    vector<vector<int>> combinations;
    vector<int> combination;

    void helper(int n, int k, int pos) {
        if (pos > n || combination.size() == k){
            if (combination.size() == k){
                combinations.push_back(combination);
            }
            return;
        }
        
        helper(n, k, pos + 1);
        combination.push_back(pos);
        helper(n, k, pos + 1);
        combination.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        helper(n, k, 1);    
        return combinations;
    }
};