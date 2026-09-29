class Solution {
    unordered_map<int, int> umap; // num, counter
    unordered_set<int>keys;
    vector<vector<int>> permutations;
    int len;

    void helper(vector<int> &perm) {
        if (perm.size() == len) {
            permutations.push_back(perm);
            return;
        }

        for (auto &pair: umap) {
            if (pair.second) {
                pair.second--;
                perm.push_back(pair.first);
                helper(perm);
                perm.pop_back();
                pair.second++;
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int num: nums) {
            umap[num]++;
        }
        len = nums.size();

        vector<int> perm;
        helper(perm);

        return permutations;
    }
};