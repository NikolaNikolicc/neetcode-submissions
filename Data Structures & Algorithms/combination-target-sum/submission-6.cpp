class Solution {
private:
    vector<vector<int>> res;
    vector<int> curr;
public:
    void helper(int pos, int sum, vector<int>& nums){
        if (pos == nums.size() || sum < 0){
            if (sum == 0){
                res.push_back(curr);
            }
            return;
        }

        curr.push_back(nums[pos]);
        helper(pos, sum - nums[pos], nums);
        curr.pop_back();

        helper(pos + 1, sum, nums);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        helper(0, target, nums);
        return res;
    }
};
