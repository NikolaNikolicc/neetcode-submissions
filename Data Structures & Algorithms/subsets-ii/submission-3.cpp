class Solution {
public:
    vector<int> sub;
    vector<vector<int>> subs;
    
    void helper(int pos, vector<int> &nums) {
        
        if (pos == nums.size()) {
            subs.push_back(sub);
            return;
        }
        int next = pos;
        while (next < nums.size() && nums[next] == nums[pos]) next++;
        helper(next, nums);
        sub.push_back(nums[pos]);
        helper(pos + 1, nums);
        sub.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(0, nums);
        return subs;
        
    }
};
