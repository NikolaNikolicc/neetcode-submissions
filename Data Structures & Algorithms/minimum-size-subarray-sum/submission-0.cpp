class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size() + 1;

        int start = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while (sum >= target && i >= start){
                minLen = min(minLen, i - start + 1);
                sum -= nums[start];
                start++;
            }
            
        }

        return (minLen == nums.size() + 1) ? 0 : minLen;
    }
};