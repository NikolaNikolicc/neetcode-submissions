class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int elem = nums[i];
            if (elem == val) {
                continue;
            }
            nums[write++] = elem;
        }
        return write;
    }
};