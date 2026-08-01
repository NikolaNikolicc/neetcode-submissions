class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int cnt = 1;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[slow] != nums[fast] || cnt < 2) {
                nums[++slow] = nums[fast];
                if (nums[slow] == nums[slow - 1]) cnt++;
                else cnt = 1;
            }
        } 
        return slow + 1;
    }
};