class Solution {
private:
    vector<vector<int>> perms;
    vector<int> perm;
    
    void helper(vector<int> nums){
        if (nums.size() == 0){
            perms.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            perm.push_back(nums[i]);
            int val = nums[i];
            nums.erase(nums.begin() + i);
            helper(nums);
            perm.pop_back();
            nums.insert(nums.begin() + i, val);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums);
        return perms;
    }
};
