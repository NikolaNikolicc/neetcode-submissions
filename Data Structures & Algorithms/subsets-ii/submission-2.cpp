class Solution {
    vector<vector<int>> subsets;
public:

    void helper(int pos, vector<int>& nums, vector<int>& subset) {
        if (pos >= nums.size()) {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[pos]);
        helper(pos + 1, nums, subset);
        subset.pop_back();

        while (pos + 1 < nums.size() && nums[pos + 1] == nums[pos]) {
            pos++;
        }
        helper(pos + 1, nums, subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        helper(0, nums, subset);
        return subsets;
    }
};
