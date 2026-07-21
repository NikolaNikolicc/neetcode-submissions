class Solution {
    vector<vector<int>> res;
public:

    void helper(int i, vector<int>& nums, vector<int>& curr) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }
        helper(i + 1, nums, curr);
        curr.push_back(nums[i]);
        helper(i + 1, nums, curr);
        curr.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        helper(0, nums, curr);
        return res;
    }
};
