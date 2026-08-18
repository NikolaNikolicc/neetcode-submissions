class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set numsSet(nums.begin(), nums.end());

        int longest = 0;
        for (auto &num: nums) {
            if (numsSet.count(num - 1)) continue;
            int curr = num, len = 0;
            while (numsSet.count(curr)) {
                curr++;
                len++;
            }
            longest = max(longest, len);
        }
        return longest;
    }
};
