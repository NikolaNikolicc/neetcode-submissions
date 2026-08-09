class NumArray {
    vector<int> left;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) {
            sum += num;
            left.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int sub = (left) ? this->left[left - 1] : 0;
        return this->left[right] - sub;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */