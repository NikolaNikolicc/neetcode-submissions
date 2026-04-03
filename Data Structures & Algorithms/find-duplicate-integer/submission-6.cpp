class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int elem = 0;
        while (true){
            if (nums[elem] == 0) return elem;
            int tmp = nums[elem];
            nums[elem] = 0;
            elem = tmp;
        }
    }
};
