class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], currMaxSum = 0;
        int minSum = nums[0], currMinSum = 0;
        int sum = 0;
        for (int num: nums) {

            sum += num;
            
            currMaxSum += num;
            currMinSum += num;
            
            maxSum = max(maxSum, currMaxSum);
            minSum = min(minSum, currMinSum);

            if (currMaxSum < 0) currMaxSum = 0;
            if (currMinSum > 0) currMinSum = 0;
        }

        return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }
};