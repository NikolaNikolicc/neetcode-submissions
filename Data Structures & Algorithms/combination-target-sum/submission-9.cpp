class Solution {
    vector<vector<int>> combinations;

    void helper(vector<int>& nums, int target, vector<int>& comb, int pos, int currSum) {
        if (currSum == target) {
            combinations.push_back(comb);
            return;
        }

        if (pos >= nums.size() || currSum > target) return;
        
        for (int i = pos; i < nums.size(); i++) {
            comb.push_back(nums[i]);
            helper(nums, target, comb, i, currSum + nums[i]);
            comb.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> comb;
        helper(nums, target, comb, 0, 0);
        return combinations;
    }
};
