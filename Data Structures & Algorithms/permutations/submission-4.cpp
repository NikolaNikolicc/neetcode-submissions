class Solution {
    vector<vector<int>> permutations;

    void helper(vector<int>& perm, vector<int>& nums) {
        if (perm.size() == nums.size()) {
            permutations.push_back(perm);
            return;
        }
        for (int num: nums) {
            if (!count(perm.begin(), perm.end(), num)) {
                perm.push_back(num);
                helper(perm, nums);
                perm.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        unordered_set<int> visited;
        helper(perm, nums);

        return permutations;
    }
};
