class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxCnt = 0;
        for (auto& elem: nums) {
            if (elem) cnt++;
            else maxCnt = max(maxCnt, cnt), cnt = 0;
        }
        return max(maxCnt, cnt);
    }
};