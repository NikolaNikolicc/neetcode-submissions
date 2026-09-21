class Solution {
    vector<vector<int>> subs;
public:
    void helper(int pos, vector<int>& nums, vector<int>& subset) {
        if (pos == nums.size()) {
            subs.push_back(subset);
            return;
        }
        helper(pos + 1, nums, subset);
        subset.push_back(nums[pos]);
        helper(pos + 1, nums, subset);
        subset.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        helper(0, nums, subset);
        return subs;
    }
};
