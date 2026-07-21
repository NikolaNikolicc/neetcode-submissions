class Solution {
public:
    int rob(vector<int>& nums) {
        int one = 0, two = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tmp = two;
            two = max(one + nums[i], two);
            one = tmp;
        }
        return two;
    }
};
