class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<int>& curr, int position, int currentSum, int target) {
        if (currentSum >= target || position == nums.size()) {
            if (currentSum == target)res.push_back(curr);
            return;
        }
        
        helper(nums, curr, position + 1, currentSum, target);
        curr.push_back(nums[position]);
        helper(nums, curr, position, currentSum + nums[position], target);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        helper(nums, curr, 0, 0, target);
        return res;
    }
};
