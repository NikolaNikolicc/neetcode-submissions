class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int totalSum = nums[0], sum = 0;

        for (int l = 0; l < nums.size(); l++){
            sum += nums[l];
            totalSum = max(totalSum, sum);
            if (sum < 0){
                sum = 0;
            } 
        }
        return totalSum;
    }
};
