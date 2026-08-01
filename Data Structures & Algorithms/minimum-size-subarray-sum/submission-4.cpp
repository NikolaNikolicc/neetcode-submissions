class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r = 0, l = 0;
        int res = nums.size() + 1, len = 0;
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            } 
            r++;
        }
        return (res == nums.size() + 1) ? 0 : res;
    }
};