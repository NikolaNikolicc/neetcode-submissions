class Solution {
public:
    vector<bool> visited;
    int target;

    bool backtrack(int pos, int kremaining, vector<int>& nums, int sum) {
        
        if (kremaining == 0) return true;

        if (target == sum) {
            return backtrack(0, kremaining - 1, nums, 0);
        }

        for (int i = pos; i < nums.size(); i++) {
            if (visited[i] || nums[i] + sum > target) continue;

            visited[i] = true;
            if (backtrack(i + 1, kremaining, nums, sum + nums[i])) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int val = 1;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k) return false;

        sort(nums.rbegin(), nums.rend());
        this->visited = vector<bool>(nums.size(), false);
        this->target = sum / k;

        return backtrack(0, k, nums, 0);
    }
};