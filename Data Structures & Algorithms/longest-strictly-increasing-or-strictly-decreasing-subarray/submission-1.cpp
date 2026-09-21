class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        int i = 1;
        int maxLen = 1, len = 1;
        bool increasing = true;
        while (i < nums.size()) {
            if ( increasing && nums[i] > nums[i - 1] || 
                !increasing && nums[i] < nums[i - 1]) {
                len++;
            } else {
                maxLen = max(maxLen, len);
                len = 1;
                if (nums[i] != nums[i - 1]) {
                    len = 2;
                    increasing = !increasing;
                }
            }
            i++;    
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
};