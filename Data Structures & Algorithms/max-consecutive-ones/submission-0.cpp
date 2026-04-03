class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int maxCnt = 0,cnt = 0;
            for (auto& elem: nums) {
                if (elem == 1) {
                    cnt++;
                } else {
                    maxCnt = max(maxCnt, cnt);
                    cnt = 0;
                }
            }
            return max(maxCnt, cnt);
        }
};