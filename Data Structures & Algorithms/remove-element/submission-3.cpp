class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int pos = 0; pos < nums.size(); pos++) {
            if (nums[pos] != val) {
                nums[slow++] = nums[pos];
            }
        }
        return slow;
    }
};