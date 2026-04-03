class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> right(nums.size() + 1, 1);

        for (int i = nums.size() - 1; i >= 0; i--){
            right[i] = right[i + 1] * nums[i];
        }

        int left = 1;

        for (int i = 0; i < nums.size(); i++){
            res[i] = left * right[i + 1];
            left *= nums[i];
        }

        return res;
    }
};
